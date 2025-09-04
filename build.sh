rm /tmp/mesa/lib/*.a
rm /tmp/mesa/lib/*.so
find -name "*.so" -exec rm {} \;
find -name "*.a" -exec rm {} \;
find -name "libgallium_dri.*" -exec rm -r {} \;


# platform_sdk >= 30 enable gralloc4
#              >= 35 enable libui

	meson setup --reconfigure "build-android" \
            --prefix=/tmp/mesa \
            --cross-file "../build-crossfile" \
            -Dplatforms=android \
            -Dplatform-sdk-version=35 \
            -Dandroid-stub=true \
            -Dandroid-libbacktrace=disabled \
            -Dandroid-strict=true \
            -Dxlib-lease=disabled \
            -Degl=true \
	    -Degl-native-platform=android \
            -Dgbm=false \
            -Dglx=disabled \
            -Dllvm=false \
            -Dopengl=false \
            -Dgles1=true \
            -Dgles2=true \
            -Dvulkan-drivers=freedreno \
            -Dtools=drm-shim \
            -Dgallium-drivers=freedreno \
            -Dfreedreno-kmds=kgsl \
	    -Dallow-fallback-for=libdrm \
            -Dbuildtype=release \
            --force-fallback-for=libdrm,libxml2 \
            -Dlibdrm:freedreno-kgsl=true \
            -Dlibdrm:freedreno=enabled \
            -Dlibdrm:default_library=static \

#	meson configure build-android/ 
          ninja -C "build-android" install
