// hidlbase_stub.cpp
#include <string>
#include <hidl/Status.h>
#include <hidl/HidlSupport.h>
#include <android/hidl/base/1.0/IBase.h>
#include <cutils/native_handle.h>

namespace android {
namespace hardware {

// ---- Status ----
__attribute__((used,visibility("default")))
std::string Status::description() const { return std::string(); }

namespace details {
__attribute__((used,visibility("default")))
void logError(const std::string&) {}
__attribute__((used,visibility("default")))
void errorWriteLog(int, const char*) {}
__attribute__((used,visibility("default")))
void logAlwaysFatal(const char*) {}
__attribute__((used,visibility("default")))
void check(bool, const char*) {}
__attribute__((used,visibility("default")))
return_status::~return_status() {}
} // namespace details

// ---- hidl_string ----
hidl_string::hidl_string() {}
hidl_string::hidl_string(const char*) {}
hidl_string::hidl_string(const hidl_string&) {}
hidl_string::hidl_string(hidl_string&&) noexcept {}
hidl_string::~hidl_string() {}
__attribute__((used,visibility("default")))
hidl_string& hidl_string::operator=(const hidl_string&) { return *this; }
__attribute__((used,visibility("default")))
hidl_string& hidl_string::operator=(hidl_string&&) noexcept { return *this; }
hidl_string::operator std::string() const { return std::string(); }
__attribute__((used,visibility("default")))
const char* hidl_string::c_str() const { return ""; }
__attribute__((used,visibility("default")))
void hidl_string::setToExternal(const char* s, size_t n) { (void)s; (void)n; }

// ---- hidl_handle ----
__attribute__((used,visibility("default")))
hidl_handle::hidl_handle() {}
__attribute__((used,visibility("default")))
hidl_handle::~hidl_handle() {}
__attribute__((used,visibility("default")))
hidl_handle::hidl_handle(const native_handle*) {}
__attribute__((used,visibility("default")))
hidl_handle::hidl_handle(const hidl_handle&) {}
__attribute__((used,visibility("default")))
hidl_handle::hidl_handle(hidl_handle&&) noexcept {}
__attribute__((used,visibility("default")))
hidl_handle& hidl_handle::operator=(const hidl_handle&) { return *this; }
__attribute__((used,visibility("default")))
hidl_handle& hidl_handle::operator=(hidl_handle&&) noexcept { return *this; }
__attribute__((used,visibility("default")))
const native_handle* hidl_handle::getNativeHandle() const { return nullptr; }
__attribute__((used,visibility("default")))
void hidl_handle::setTo(native_handle*, bool) {}

} // namespace hardware
} // namespace android

// ---- IBase ----
namespace android {
namespace hidl {
namespace base {
namespace V1_0 {

__attribute__((used,visibility("default")))
::android::hardware::Return<void>
IBase::interfaceChain(interfaceChain_cb) {
    return ::android::hardware::Return<void>();
}

__attribute__((used,visibility("default")))
::android::hardware::Return<void>
IBase::interfaceDescriptor(interfaceDescriptor_cb) {
    return ::android::hardware::Return<void>();
}

__attribute__((used,visibility("default")))
::android::hardware::Return<void>
IBase::getHashChain(getHashChain_cb) {
    return ::android::hardware::Return<void>();
}

__attribute__((used,visibility("default")))
::android::hardware::Return<void>
IBase::debug(const ::android::hardware::hidl_handle&,
             const ::android::hardware::hidl_vec<::android::hardware::hidl_string>&) {
    return ::android::hardware::Return<void>();
}

__attribute__((used,visibility("default")))
::android::hardware::Return<void>
IBase::setHALInstrumentation() {
    return ::android::hardware::Return<void>();
}

__attribute__((used,visibility("default")))
::android::hardware::Return<bool>
IBase::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>&,
                   uint64_t) {
    return ::android::hardware::Return<bool>(false);
}

__attribute__((used,visibility("default")))
::android::hardware::Return<bool>
IBase::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>&) {
    return ::android::hardware::Return<bool>(false);
}

__attribute__((used,visibility("default")))
::android::hardware::Return<void>
IBase::ping() {
    return ::android::hardware::Return<void>();
}

__attribute__((used,visibility("default")))
::android::hardware::Return<void>
IBase::getDebugInfo(getDebugInfo_cb) {
    return ::android::hardware::Return<void>();
}

__attribute__((used,visibility("default")))
::android::hardware::Return<void>
IBase::notifySyspropsChanged() {
    return ::android::hardware::Return<void>();
}

} // namespace V1_0
} // namespace base
} // namespace hidl
} // namespace android

// ---- Threadpool control ----
namespace android {
namespace hardware {
__attribute__((used,visibility("default")))
void configureRpcThreadpool(size_t, bool) {}
__attribute__((used,visibility("default")))
void joinRpcThreadpool() {}
} // namespace hardware
} // namespace android


// hidl_string_stub.cpp
// Stub for missing hidl_string symbols. Build into libhidlbase.so.
// Preserves exact prototypes and exports with used + default visibility.

#include <hidl/HidlSupport.h>
#include <string>
#include <cstring>

namespace android {
namespace hardware {

__attribute__((used,visibility("default")))
hidl_string& hidl_string::operator=(const char* s) {
    if (s) {
        this->setToExternal(s, std::strlen(s));
    } else {
        this->setToExternal("", 0);
    }
    return *this;
}

__attribute__((used,visibility("default")))
hidl_string::hidl_string(
    const std::basic_string<char,
                                    std::char_traits<char>,
                                    std::allocator<char>>& s) {
    *this = s.c_str();
}

} // namespace hardware
} // namespace android

/*
 * hidl_return_status_stub.cpp
 * No-op implementation of android::hardware::details::return_status::onValueRetrieval() const
 * to satisfy link-time dependencies from HIDL Return<T> conversions.
 */

#include <hidl/Status.h>

namespace android::hardware::details {

__attribute__((used,visibility("default")))
void return_status::onValueRetrieval() const {
    // Intentionally no-op for stub builds.
}

} // namespace android::hardware::details
