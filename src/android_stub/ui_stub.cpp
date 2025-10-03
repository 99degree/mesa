/*
 * ui_stub.cpp
 * Stub implementation of android::GraphicBufferMapper (VNDK v34) and required
 * Singleton symbols. Link-time only; no real buffer management.
 *
 * Key: Provide a dummy complete type for android::GrallocMapper to satisfy
 * unique_ptr<const GrallocMapper> destructor checks in libc++.
 */

#include <vector>
#include <cstdint>
#include <cstddef>

#include <cutils/native_handle.h>
#include <ui/GraphicBufferMapper.h>
#include <utils/Singleton.h>
#include <utils/Mutex.h>

namespace android {
// The VNDK headers forward-declare GrallocMapper. Define a dummy complete type
// so unique_ptr<const GrallocMapper> can be destroyed without incomplete-type errors.
class GrallocMapper {};
} // namespace android

namespace android {

// Define static members of Singleton<GraphicBufferMapper>.
template<> Mutex Singleton<GraphicBufferMapper>::sLock{};
template<> GraphicBufferMapper* Singleton<GraphicBufferMapper>::sInstance = nullptr;

// Stub constructor (do NOT define the destructor here).
__attribute__((used,visibility("default")))
GraphicBufferMapper::GraphicBufferMapper() {}

// Missing symbol stubs
__attribute__((used,visibility("default")))
status_t GraphicBufferMapper::importBufferNoValidate(
        const native_handle_t* /*handle*/,
        const native_handle_t** outBufferHandle) {
    if (outBufferHandle) *outBufferHandle = nullptr;
    return NO_ERROR;
}

__attribute__((used,visibility("default")))
status_t GraphicBufferMapper::freeBuffer(const native_handle_t* /*handle*/) {
    return NO_ERROR;
}

// Existing stubs
__attribute__((used,visibility("default")))
status_t GraphicBufferMapper::getPixelFormatFourCC(
        const native_handle_t* /*handle*/,
        unsigned int* outFourcc) {
    if (outFourcc) *outFourcc = 0;
    return NO_ERROR;
}

__attribute__((used,visibility("default")))
status_t GraphicBufferMapper::getPixelFormatModifier(
        const native_handle_t* /*handle*/,
        uint64_t* outModifier) {
    if (outModifier) *outModifier = 0;
    return NO_ERROR;
}

__attribute__((used,visibility("default")))
status_t GraphicBufferMapper::getWidth(
        const native_handle_t* /*handle*/,
        uint64_t* outWidth) {
    if (outWidth) *outWidth = 0;
    return NO_ERROR;
}

__attribute__((used,visibility("default")))
status_t GraphicBufferMapper::getHeight(
        const native_handle_t* /*handle*/,
        uint64_t* outHeight) {
    if (outHeight) *outHeight = 0;
    return NO_ERROR;
}

__attribute__((used,visibility("default")))
status_t GraphicBufferMapper::getPlaneLayouts(
        const native_handle_t* /*handle*/,
        std::vector<aidl::android::hardware::graphics::common::PlaneLayout>* outLayouts) {
    if (outLayouts) outLayouts->clear();
    return NO_ERROR;
}

} // namespace android
