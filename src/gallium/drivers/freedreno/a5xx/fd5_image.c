/*
 * Copyright (C) 2017 Rob Clark <robclark@freedesktop.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Authors:
 *    Rob Clark <robclark@freedesktop.org>
 */

#include "pipe/p_state.h"

#include "freedreno_resource.h"
#include "fd5_image.h"
#include "fd5_format.h"
#include "fd5_texture.h"

static enum a4xx_state_block texsb[] = {
	[PIPE_SHADER_COMPUTE] = SB4_CS_TEX,
	[PIPE_SHADER_FRAGMENT] = SB4_FS_TEX,
};

static enum a4xx_state_block imgsb[] = {
	[PIPE_SHADER_COMPUTE] = SB4_CS_SSBO,
	[PIPE_SHADER_FRAGMENT] = SB4_SSBO,
};

struct fd5_image {
	enum pipe_format pfmt;
	enum a5xx_tex_fmt fmt;
	enum a5xx_tex_fetchsize fetchsize;
	enum a5xx_tex_type type;
	bool srgb;
	uint32_t cpp;
	uint32_t width;
	uint32_t height;
	uint32_t depth;
	uint32_t pitch;
	uint32_t array_pitch;
	struct fd_bo *bo;
	uint32_t offset;
};

static void translate_image(struct fd5_image *img, struct pipe_image_view *pimg)
{
	enum pipe_format format = pimg->format;
	struct pipe_resource *prsc = pimg->resource;
	struct fd_resource *rsc = fd_resource(prsc);
	struct fdl_slice *slice = NULL;
	unsigned lvl;

	if (!pimg->resource) {
		memset(img, 0, sizeof(*img));
		return;
	}

	img->pfmt      = format;
	img->fmt       = fd5_pipe2tex(format);
	img->fetchsize = fd5_pipe2fetchsize(format);
	img->type      = fd5_tex_type(prsc->target);
	img->srgb      = util_format_is_srgb(format);
	img->cpp       = rsc->layout.cpp;
	img->bo        = rsc->bo;

	if (prsc->target == PIPE_BUFFER) {
		lvl = 0;
		img->offset = pimg->u.buf.offset;
		img->pitch  = pimg->u.buf.size;
	} else {
		lvl = pimg->u.tex.level;
		slice = fd_resource_slice(rsc, lvl);
		img->offset = fd_resource_offset(rsc, lvl, pimg->u.tex.first_layer);
		img->pitch  = slice->pitch;
	}

	img->width     = u_minify(prsc->width0, lvl);
	img->height    = u_minify(prsc->height0, lvl);

	unsigned layers = pimg->u.tex.last_layer - pimg->u.tex.first_layer + 1;

	switch (prsc->target) {
	case PIPE_TEXTURE_RECT:
	case PIPE_TEXTURE_1D:
	case PIPE_TEXTURE_2D:
		img->array_pitch = rsc->layout.layer_size;
		img->depth = 1;
		break;
	case PIPE_TEXTURE_1D_ARRAY:
	case PIPE_TEXTURE_2D_ARRAY:
		img->array_pitch = rsc->layout.layer_size;
		img->depth = layers;
		break;
	case PIPE_TEXTURE_CUBE:
	case PIPE_TEXTURE_CUBE_ARRAY:
		img->array_pitch = rsc->layout.layer_size;
		img->depth = layers;
		break;
	case PIPE_TEXTURE_3D:
		img->array_pitch = slice->size0;
		img->depth = u_minify(prsc->depth0, lvl);
		break;
	default:
		img->array_pitch = 0;
		img->depth = 0;
		break;
	}
}

static void emit_image_tex(struct fd_ringbuffer *ring, unsigned slot,
		struct fd5_image *img, enum pipe_shader_type shader)
{
	OUT_PKT7(ring, CP_LOAD_STATE4, 3 + 12);
	OUT_RING(ring, CP_LOAD_STATE4_0_DST_OFF(slot) |
		CP_LOAD_STATE4_0_STATE_SRC(SS4_DIRECT) |
		CP_LOAD_STATE4_0_STATE_BLOCK(texsb[shader]) |
		CP_LOAD_STATE4_0_NUM_UNIT(1));
	OUT_RING(ring, CP_LOAD_STATE4_1_STATE_TYPE(ST4_CONSTANTS) |
		CP_LOAD_STATE4_1_EXT_SRC_ADDR(0));
	OUT_RING(ring, CP_LOAD_STATE4_2_EXT_SRC_ADDR_HI(0));

	OUT_RING(ring, A5XX_TEX_CONST_0_FMT(img->fmt) |
		fd5_tex_swiz(img->pfmt, PIPE_SWIZZLE_X, PIPE_SWIZZLE_Y,
			PIPE_SWIZZLE_Z, PIPE_SWIZZLE_W) |
		COND(img->srgb, A5XX_TEX_CONST_0_SRGB));
	OUT_RING(ring, A5XX_TEX_CONST_1_WIDTH(img->width) |
		A5XX_TEX_CONST_1_HEIGHT(img->height));
	OUT_RING(ring, A5XX_TEX_CONST_2_FETCHSIZE(img->fetchsize) |
		A5XX_TEX_CONST_2_TYPE(img->type) |
		A5XX_TEX_CONST_2_PITCH(img->pitch));
	OUT_RING(ring, A5XX_TEX_CONST_3_ARRAY_PITCH(img->array_pitch));
	if (img->bo) {
		OUT_RELOC(ring, img->bo, img->offset,
				(uint64_t)A5XX_TEX_CONST_5_DEPTH(img->depth) << 32, 0);
	} else {
		OUT_RING(ring, 0x00000000);
		OUT_RING(ring, A5XX_TEX_CONST_5_DEPTH(img->depth));
	}
	OUT_RING(ring, 0x00000000);
	OUT_RING(ring, 0x00000000);
	OUT_RING(ring, 0x00000000);
	OUT_RING(ring, 0x00000000);
	OUT_RING(ring, 0x00000000);
	OUT_RING(ring, 0x00000000);
}

static void emit_image_ssbo(struct fd_ringbuffer *ring, unsigned slot,
		struct fd5_image *img, enum pipe_shader_type shader)
{
	OUT_PKT7(ring, CP_LOAD_STATE4, 3 + 2);
	OUT_RING(ring, CP_LOAD_STATE4_0_DST_OFF(slot) |
		CP_LOAD_STATE4_0_STATE_SRC(SS4_DIRECT) |
		CP_LOAD_STATE4_0_STATE_BLOCK(imgsb[shader]) |
		CP_LOAD_STATE4_0_NUM_UNIT(1));
	OUT_RING(ring, CP_LOAD_STATE4_1_STATE_TYPE(1) |
		CP_LOAD_STATE4_1_EXT_SRC_ADDR(0));
	OUT_RING(ring, CP_LOAD_STATE4_2_EXT_SRC_ADDR_HI(0));
	OUT_RING(ring, A5XX_SSBO_1_0_FMT(img->fmt) |
		A5XX_SSBO_1_0_WIDTH(img->width));
	OUT_RING(ring, A5XX_SSBO_1_1_HEIGHT(img->height) |
		A5XX_SSBO_1_1_DEPTH(img->depth));

	OUT_PKT7(ring, CP_LOAD_STATE4, 3 + 2);
	OUT_RING(ring, CP_LOAD_STATE4_0_DST_OFF(slot) |
		CP_LOAD_STATE4_0_STATE_SRC(SS4_DIRECT) |
		CP_LOAD_STATE4_0_STATE_BLOCK(imgsb[shader]) |
		CP_LOAD_STATE4_0_NUM_UNIT(1));
	OUT_RING(ring, CP_LOAD_STATE4_1_STATE_TYPE(2) |
		CP_LOAD_STATE4_1_EXT_SRC_ADDR(0));
	OUT_RING(ring, CP_LOAD_STATE4_2_EXT_SRC_ADDR_HI(0));
	if (img->bo) {
		OUT_RELOC(ring, img->bo, img->offset, 0, 0);
	} else {
		OUT_RING(ring, 0x00000000);
		OUT_RING(ring, 0x00000000);
	}
}

/* Emit required "SSBO" and sampler state.  The sampler state is used by the
 * hw for imageLoad(), and "SSBO" state for imageStore().  Returns max sampler
 * used.
 */
void
fd5_emit_images(struct fd_context *ctx, struct fd_ringbuffer *ring,
		enum pipe_shader_type shader, const struct ir3_shader_variant *v)
{
	struct fd_shaderimg_stateobj *so = &ctx->shaderimg[shader];
	unsigned enabled_mask = so->enabled_mask;
	const struct ir3_ibo_mapping *m = &v->image_mapping;

	while (enabled_mask) {
		unsigned index = u_bit_scan(&enabled_mask);
		struct fd5_image img;

		translate_image(&img, &so->si[index]);

		emit_image_tex(ring, m->image_to_tex[index] + m->tex_base, &img, shader);
		emit_image_ssbo(ring, v->shader->nir->info.num_ssbos + index, &img, shader);
	}
}