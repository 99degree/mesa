/*
 * Copyright © 2013 Intel Corporation
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
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "piglit-util-gl.h"
#include "xfb3_common.h"

/**
 * @file set_varyings_with_invalid_args.c 
 *
 * Tests that TransformFeedbackVaryings() does not accept non-existing program
 * and that the upper limit for the number of attributes is guarded. The spec:
 *
 * "The error INVALID_VALUE is generated by TransformFeedbackVaryings if
 *  <program> is not the name of a program object, or if <bufferMode> is
 *  SEPARATE_ATTRIBS and <count> is greater than the limit
 *  MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS."
 *
 * Additionally accept following common rule with shader object API, specified
 * by the 'Shader Objects' section of OpenGL spec:
 *
 * "Commands that accept shader or program object names will generate the error
 * INVALID VALUE if the provided name is not the name of either a shader or pro-
 * gram object and INVALID OPERATION if the provided name identifies an object
 * that is not the expected type."
 */

PIGLIT_GL_TEST_CONFIG_BEGIN

	config.supports_gl_compat_version = 32;
	config.supports_gl_core_version = 32;
	config.khr_no_error_support = PIGLIT_HAS_ERRORS;

PIGLIT_GL_TEST_CONFIG_END

static const char gs_simple_text[] =
	"#version 150\n"
	"layout(points) in;\n"
	"layout(points, max_vertices = 1) out;\n"
	"out float x1_out;\n"
	"void main() {\n"
	"  gl_Position = gl_in[0].gl_Position;\n"
	"  x1_out = 1.0;\n"
	"}";

static const char *varyings[] = { "x1_out" };

/**
 * Dynamically reserve space and setup an array of 'n' string pointers all
 * referring to 'varyings'. For testing the upper bound of attributes expected
 * the string values do not need to be mutually unique but in order to respect
 * the API there should be as many strings available in the array as claimed.
 */
static void
try_max_varyings(GLuint prog, unsigned n)
{
        const char **var_array;
        unsigned i;

        var_array = (const char**)malloc(n * sizeof(const char *));

        for (i = 0; i < n; ++i)
        	var_array[i] = varyings[0];

        glTransformFeedbackVaryings(prog, n, var_array, GL_SEPARATE_ATTRIBS);

        free(var_array);
}

void
piglit_init(int argc, char **argv)
{
	GLuint vs, gs, prog;
	GLint max_attrib_n;

	piglit_require_extension("GL_ARB_transform_feedback3");

	glGetIntegerv(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS,
		&max_attrib_n);
	if (!max_attrib_n) {
		printf("Maximum number of separete attributes is zero\n");
		piglit_report_result(PIGLIT_FAIL);
	}

	vs = piglit_compile_shader_text(GL_VERTEX_SHADER, vs_pass_thru_text);
	gs = piglit_compile_shader_text(GL_GEOMETRY_SHADER, gs_simple_text);

	if (!vs || !gs)
		piglit_report_result(PIGLIT_FAIL);

	prog = glCreateProgram();
	glAttachShader(prog, vs);
	glAttachShader(prog, gs);
	glLinkProgram(prog);

	if(!piglit_link_check_status(prog))
		piglit_report_result(PIGLIT_FAIL);

	/* Try invalid program */
	glTransformFeedbackVaryings(42, ARRAY_SIZE(varyings), varyings,
				GL_INTERLEAVED_ATTRIBS);
	if (!piglit_check_gl_error(GL_INVALID_VALUE))
		piglit_report_result(PIGLIT_FAIL);

	/* Try shader in place of program. */
	glTransformFeedbackVaryings(vs, ARRAY_SIZE(varyings), varyings,
				GL_INTERLEAVED_ATTRIBS);
	if (!piglit_check_gl_error(GL_INVALID_OPERATION))
		piglit_report_result(PIGLIT_FAIL);

	/* Try too many attributes */
	try_max_varyings(prog, max_attrib_n + 1);
	if (!piglit_check_gl_error(GL_INVALID_VALUE))
		piglit_report_result(PIGLIT_FAIL);

	piglit_report_result(PIGLIT_PASS);
}

enum piglit_result
piglit_display(void)
{
	/* Should never be reached */
	return PIGLIT_FAIL;
}