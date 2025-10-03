if with_android_stub

ndk_root = '/usr/android-ndk-r27d'

inc_include += [include_directories('.')]

# Extended include paths for Android VNDK v34
# Each path below has a comment describing what headers it provides
inc_extra_v34 = [
  # android-base/unique_fd.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/libbase/include/'),
  # system/core/libsystem/
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libsystem/'),
  # hardware/gralloc.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/hardware/libhardware/include/'),
  # system/graphics-base-v1.0.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libsystem/include/'),
  # sync/sync.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libsync/include/'),
  # libvndksupport
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libvndksupport/include/'),
  # libsysutils
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libsysutils/'),
  # graphics.common-V4 AIDL headers
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/common/aidl/android.hardware.graphics.common-V4-ndk-source/gen/include/'),
  # libcutils
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libcutils/include/'),
  # log/log.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/logging/liblog/include_vndk/'),
  # BufferDescriptorInfo.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/allocator/aidl/android.hardware.graphics.allocator-V2-ndk-source/gen/include/'),
  # graphics.common@1.2
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/common/1.2/android.hardware.graphics.common@1.2_genc++_headers/gen/'),
  # graphics.common@1.1
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/common/1.1/android.hardware.graphics.common@1.1_genc++_headers/gen/'),
  # graphics.common@1.0
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/common/1.0/android.hardware.graphics.common@1.0_genc++_headers/gen/'),
  # Hidlsupport.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/libhidl/base/include/'),
  # utils/Error.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libutils/include/'),
  # fmq/MQDescriptorBase.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/libfmq/base/'),
  # IMapper 4.0
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/mapper/4.0/android.hardware.graphics.mapper@4.0_genc++_headers/gen/'),
  # IBase 1.0
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/system/libhidl/transport/base/1.0/android.hidl.base@1.0_genc++_headers/gen/'),
  # IServiceNotification 1.0
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/system/libhidl/transport/manager/1.0/android.hidl.manager@1.0_genc++_headers/gen/'),
  # gralloctypes/Gralloc4.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/gralloc/types/include/'),
  # system/window.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/nativewindow/include/'),
  # nativebase.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/nativebase/include/'),
  #
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/common/aidl/android.hardware.common-V2-ndk-source/gen/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/binder/ndk/include_platform/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/allocator/4.0/android.hardware.graphics.allocator@4.0_genc++_headers/gen/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/common/aidl/android.hardware.graphics.common-V4-ndk-source/gen/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/libhidl/transport/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/binder/include/'),
  # framework and libhwbinder both have IBinder.h
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/libhwbinder/include/'),
  # local shim includes
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/hardware/libhardware/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/core/libsync/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/hardware/libhardware/include/'),
#'./subprojects/libdrm/android/',
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/ui/include_vndk/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/composer/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/composer/aidl/android.hardware.graphics.composer3-V1-ndk-source/gen/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/frameworks/native/libs/gui/libgui_aidl_static/android_vendor.34_arm_armv8-a_static/gen/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/generated-headers/hardware/interfaces/graphics/common/aidl/android.hardware.graphics.common-V4-ndk-source/gen/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v30/arm64/include/generated-headers/hardware/interfaces/graphics/composer/2.1/android.hardware.graphics.composer@2.1_genc++_headers/gen/'),
# make use of ui/include_vndk first, then use ui/include/
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/ui/include_vndk/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/ui/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/frameworks/native/libs/math/include/'),
  join_paths(ndk_root, 'prebuilt/vndk/v34/arm64/include/system/libfmq/include/'),
]

foreach incl : inc_extra_v34
  inc_include += include_directories(incl, is_system: true)
endforeach

inc_include += include_directories(
  join_paths('../../', 'include/stable-c-v34/include/'),
  join_paths('../../', 'include/stable-c-v34/implutils/include/'),
  join_paths('../../', 'include/'),
)

common_cflags = []

common_cpp_flags = [
# '-D__NR_memfd_create',
#'-DHAS_DMABUF_SYSTEM_HEAP',
#'-D_LIBCPP___CONFIG_SITE',
#'-D_LIBCPP_ABI_VERSION=1',
#'-D_LIBCPP_ABI_NAMESPACE __ndk1',
#'-D_LIBCPP_HAS_NO_VENDOR_AVAILABILITY_ANNOTATIONS',
#'-D_LIBCPP_HAS_NO_STD_MODULES',
#'-D_LIBCPP_HAS_NO_TIME_ZONE_DATABASE',
#'-D_LIBCPP_PSTL_CPU_BACKEND_THREAD',
#'-D_LIBCPP_HARDENING_MODE_DEFAULT=2',
#'-D_LIBCPP_ABI_NAMESPACE=__1',
#'-D__ANDROID_API__=34',

  '-D__ANDROID__',
  '-D__ANDROID_MIN_SDK_VERSION__=34',
  '-DANDROID_API_LEVEL=34',
#    '-DUSE_IMAPPER4_METADATA_API',
  '-O0', '-g',
  '-fPIC',
  '-fvisibility=default',
#  '-fno-inline',
  '-fexceptions',
  '-fno-rtti',
  '-Wno-unused-parameter',
]

common_link_flags = [
  '-Wl,--no-gc-sections',
#'-Wl,--whole-archive', '-lc++_static', '-Wl,--no-whole-archive',
#  '-Wl,-soname,libhidlbase.so', # or the actual SONAME you’re stubbing
#  '-shared',
#  '-nostdlib++',
#  '-llog',
#  '-lc',
#  '-lc++',
#'-static-libstdc++',
#'-lc++abi',
#'-static',
#  '-static-libstdc++',
#  '-stdlib=libstdc++',
#    '-lc++_static',
#    '-lc++abi',
#    '-lm',
#    '-L'+libcxx_search_path',
#  '-l:libc++_shared.so',
#  '-Wl,--no-as-needed',
#   '-lc++', '-lc++abi',
#   '-latomic',
#  '-lhidlbase',
#'-Wl,-Bstatic', '-lc++_static', '-lc++abi', '-Wl,-Bdynamic',
  '-lc++_shared',
]

# from mesa android-stub
base_deps = []
stub_lib = []
stub_libs = []
prefix = ''
lib_names = [
 'cutils', 'hardware', 'log', 'base',
 'nativewindow', 'sync', 'binder_ndk', 'utils', 'fmq',
 'hidltransport', 'gralloctypes', 'hidlbase', 'ui', 'binder',
 'android.hardware.graphics.composer@2.1',
 'android.hardware.graphics.mapper@4.0',
]

#  if with_libbacktrace
#    lib_names += ['backtrace']
#  endif
foreach lib : lib_names
  if lib.contains('@')
    prefix = ''
  else
    prefix = 'lib'
  endif

  stub_lib = shared_library(
    lib,
    files('' + lib + '_stub.cpp'),
    include_directories : inc_include,

    # Compiler flags: keep symbols visible, disable optimizations that strip them
    c_args: ['-fvisibility=default', '-fno-lto', '-fno-inline'],
    cpp_args: ['-fvisibility=default', '-fno-lto', '-fno-inline'] + [common_cpp_flags],

    # Linker flags: don’t drop sections, export everything
    link_args: [
      '-fvisibility=default',
      '-Wl,--unresolved-symbols=ignore-all',
      '-Wl,--export-dynamic',
      '-Wl,--no-gc-sections',
      '-Wl,--allow-multiple-definition',
#      '-Wl,--version-script=' + meson.current_source_dir() + '/export_all.map',
      
    ] + common_link_flags,
    name_prefix : prefix,

    install : false,
  )
  stub_libs += stub_lib
  base_deps += declare_dependency(
	link_with : stub_lib
  )
endforeach

stub_lib = shared_library(
  'c++_shared',
  files('c++_shared_stub.cpp'),
  c_args: ['-fvisibility=default', '-fno-lto', '-fno-inline'],
  cpp_args: ['-fvisibility=default', '-fno-lto', '-fno-inline'],
  link_args: [
    '-Wl,--unresolved-symbols=ignore-all',
    '-Wl,--export-dynamic',
    '-Wl,--no-gc-sections',
    '-Wl,--allow-multiple-definition',
  ],
  install: false,
)

stub_libs += stub_lib

dep_android += [base_deps, declare_dependency(
        link_with : stub_lib
)]

endif
