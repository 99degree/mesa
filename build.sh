rm /tmp/mesa/lib/*.a
rm /tmp/mesa/lib/*.so
find -name "*.so" -exec rm {} \;
find -name "*.a" -exec rm {} \;
find -name "libgallium_dri.*" -exec rm -r {} \;

	meson --reconfigure "build-android" \
            --prefix=/tmp/mesa \
            --cross-file "../build-crossfile" \
            -Dplatforms=android \
            -Dplatform-sdk-version=34 \
            -Dandroid-stub=true \
            -Dandroid-libbacktrace=disabled \
            -Dandroid-strict=true \
            -Dxlib-lease=disabled \
            -Degl=true \
            -Dgbm=false \
            -Dglx=disabled \
            -Dllvm=false \
            -Dopengl=false \
            -Dgles1=true \
            -Dgles2=true \
            -Dvulkan-drivers=freedreno \
            -Dtools=drm-shim \
            -Dgallium-drivers=zink,freedreno \
            -Dfreedreno-kmds=kgsl,msm \
	    -Dallow-fallback-for=libdrm \
            -Dbuildtype=release \
            --force-fallback-for=libdrm,libxml2 \
            -Dlibdrm:freedreno-kgsl=true \
            -Dlibdrm:freedreno=enabled \
            -Dlibdrm:default_library=static \

          ninja -C "build-android" install
