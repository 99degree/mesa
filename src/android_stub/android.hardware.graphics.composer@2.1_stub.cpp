// android.hardware.graphics.composer@2.1_stub.cpp
// Drop-in stub for android.hardware.graphics.composer@2.1 (VNDK v30/v34).
// Non-functional; preserves exact signatures and typedefs used in generated headers.
// All exported methods are marked used + default visibility.

#include <string>
#include <functional>

#include <android/hardware/graphics/composer/2.1/IComposer.h>
#include <android/hardware/graphics/composer/2.1/IComposerClient.h>
#include <android/hardware/graphics/composer/2.1/IComposerCallback.h>
#include <android/hardware/graphics/common/1.0/types.h>

#include <hidl/MQDescriptor.h>
#include <hidl/HidlSupport.h>
#include <hidl/Status.h>

#include <android/hidl/base/1.0/IBase.h>

#include <utils/StrongPointer.h>

namespace ahw = ::android::hardware;
namespace common10 = ::android::hardware::graphics::common::V1_0;
namespace composer21 = ::android::hardware::graphics::composer::V2_1;

using ::android::sp;
using ::android::hardware::Void;

using IComposer         = composer21::IComposer;
using IComposerClient   = composer21::IComposerClient;
using IComposerCallback = composer21::IComposerCallback;
using Error             = composer21::Error;

namespace android {
namespace hardware {
namespace graphics {
namespace composer {
namespace V2_1 {

// Public descriptors (dynamic data symbols)
__attribute__((used,visibility("default")))
const char* IComposer::descriptor =
        "android.hardware.graphics.composer@2.1::IComposer";
__attribute__((used,visibility("default")))
const char* IComposerClient::descriptor =
        "android.hardware.graphics.composer@2.1::IComposerClient";
__attribute__((used,visibility("default")))
const char* IComposerCallback::descriptor =
        "android.hardware.graphics.composer@2.1::IComposerCallback";

// No-op client implementing 2.1 pure virtuals
struct ComposerClientNoop : public IComposerClient {
    // Layer management
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    createLayer(uint64_t /*display*/, uint32_t /*bufferSlotCount*/,
                IComposerClient::createLayer_cb cb) override {
        cb(Error::NONE, static_cast<uint64_t>(0));
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<Error>
    destroyLayer(uint64_t /*display*/, uint64_t /*layer*/) override {
        return Error::NONE;
    }

    // Display config/state
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    getDisplayConfigs(uint64_t /*display*/,
                      IComposerClient::getDisplayConfigs_cb cb) override {
        cb(Error::NONE, {});
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    getDisplayName(uint64_t /*display*/,
                   IComposerClient::getDisplayName_cb cb) override {
        cb(Error::NONE, ahw::hidl_string("Composer21Stub"));
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    getDisplayType(uint64_t /*display*/,
                   IComposerClient::getDisplayType_cb cb) override {
        cb(Error::NONE, IComposerClient::DisplayType::INVALID);
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    getDozeSupport(uint64_t /*display*/,
                   IComposerClient::getDozeSupport_cb cb) override {
        cb(Error::NONE, false);
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    getHdrCapabilities(uint64_t /*display*/,
                       IComposerClient::getHdrCapabilities_cb cb) override {
        cb(Error::NONE, ahw::hidl_vec<common10::Hdr>{}, 0.0f, 0.0f, 0.0f);
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    getDisplayAttribute(uint64_t /*display*/, uint32_t /*config*/,
                        IComposerClient::Attribute /*attribute*/,
                        IComposerClient::getDisplayAttribute_cb cb) override {
        cb(Error::NONE, 0);
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    getActiveConfig(uint64_t /*display*/,
                    IComposerClient::getActiveConfig_cb cb) override {
        cb(Error::NONE, 0U);
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<Error>
    setActiveConfig(uint64_t /*display*/, uint32_t /*config*/) override {
        return Error::NONE;
    }

    // Power/vsync/color
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<Error>
    setPowerMode(uint64_t /*display*/, IComposerClient::PowerMode /*mode*/) override {
        return Error::NONE;
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<Error>
    setVsyncEnabled(uint64_t /*display*/, IComposerClient::Vsync /*enabled*/) override {
        return Error::NONE;
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<Error>
    setColorMode(uint64_t /*display*/, common10::ColorMode /*mode*/) override {
        return Error::NONE;
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    getColorModes(uint64_t /*display*/,
                  IComposerClient::getColorModes_cb cb) override {
        cb(Error::NONE, ahw::hidl_vec<common10::ColorMode>{});
        return Void();
    }

    // Virtual displays
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    createVirtualDisplay(uint32_t /*width*/, uint32_t /*height*/,
                         common10::PixelFormat /*formatHint*/,
                         uint32_t /*outputBufferSlotCount*/,
                         IComposerClient::createVirtualDisplay_cb cb) override {
        cb(Error::NONE, static_cast<uint64_t>(0), common10::PixelFormat::RGBA_8888);
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<Error>
    destroyVirtualDisplay(uint64_t /*display*/) override {
        return Error::NONE;
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<uint32_t>
    getMaxVirtualDisplayCount() override {
        return static_cast<uint32_t>(0);
    }

    // Client target support/slots
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<Error>
    getClientTargetSupport(uint64_t /*display*/,
                           uint32_t /*width*/, uint32_t /*height*/,
                           common10::PixelFormat /*format*/,
                           common10::Dataspace /*dataspace*/) override {
        return Error::NONE;
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<Error>
    setClientTargetSlotCount(uint64_t /*display*/, uint32_t /*count*/) override {
        return Error::NONE;
    }

    // Command queues (FMQ)
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    getOutputCommandQueue(IComposerClient::getOutputCommandQueue_cb cb) override {
        ahw::MQDescriptor<uint32_t, ahw::kSynchronizedReadWrite> out;
        cb(Error::NONE, out);
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<Error>
    setInputCommandQueue(const ahw::MQDescriptor<uint32_t, ahw::kSynchronizedReadWrite>& /*in*/) override {
        return Error::NONE;
    }

    // Batched commands
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    executeCommands(uint32_t /*inLength*/,
                    const ahw::hidl_vec<ahw::hidl_handle>& /*inHandles*/,
                    IComposerClient::executeCommands_cb cb) override {
        cb(Error::NONE, false, 0U, ahw::hidl_vec<ahw::hidl_handle>{});
        return Void();
    }

    // Callbacks
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    registerCallback(const sp<IComposerCallback>& /*callback*/) override {
        return Void();
    }
};

// Minimal IComposer handing out the no-op client
struct ComposerStub : public IComposer {
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    getCapabilities(IComposer::getCapabilities_cb cb) override {
        cb(ahw::hidl_vec<IComposer::Capability>{});
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    dumpDebugInfo(IComposer::dumpDebugInfo_cb cb) override {
        cb(ahw::hidl_string("composer@2.1 stub"));
        return Void();
    }
    __attribute__((used,visibility("default")))
    ::android::hardware::Return<void>
    createClient(IComposer::createClient_cb cb) override {
        sp<IComposerClient> client = new ComposerClientNoop();
        cb(Error::NONE, client);
        return Void();
    }
};

// ----------------------------------------------------------------------
// IBase / IComposer inherited methods (exact typedef signatures)
// ----------------------------------------------------------------------

#define STUB_ATTR __attribute__((used,visibility("default")))

STUB_ATTR
::android::status_t
IComposer::registerAsService(const std::string& /*serviceName*/) {
    return ::android::OK;
}

STUB_ATTR
::android::hardware::Return<void>
IComposer::debug(const ahw::hidl_handle& /*fd*/,
                 const ahw::hidl_vec<ahw::hidl_string>& /*options*/) {
    return {};
}

// NOTE: use the typedef names from the generated headers.
STUB_ATTR
::android::hardware::Return<void>
IComposer::interfaceChain(interfaceChain_cb _hidl_cb) {
    if (_hidl_cb) {
        ahw::hidl_vec<ahw::hidl_string> v;
        v.resize(0);
        _hidl_cb(v);
    }
    return {};
}

STUB_ATTR
::android::hardware::Return<void>
IComposer::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) {
    if (_hidl_cb) _hidl_cb(ahw::hidl_string(""));
    return {};
}

STUB_ATTR
::android::hardware::Return<void>
IComposer::getHashChain(getHashChain_cb _hidl_cb) {
    if (_hidl_cb) {
        ahw::hidl_vec<ahw::hidl_array<uint8_t, 32>> hashes;
        hashes.resize(0);
        _hidl_cb(hashes);
    }
    return {};
}

STUB_ATTR
::android::hardware::Return<void>
IComposer::setHALInstrumentation() { return {}; }

STUB_ATTR
::android::hardware::Return<bool>
IComposer::linkToDeath(const sp<ahw::hidl_death_recipient>& /*recipient*/,
                       uint64_t /*cookie*/) {
    return ::android::hardware::Return<bool>(true);
}

STUB_ATTR
::android::hardware::Return<void>
IComposer::ping() { return {}; }

STUB_ATTR
::android::hardware::Return<void>
IComposer::getDebugInfo(getDebugInfo_cb _hidl_cb) {
    if (_hidl_cb) {
        ::android::hidl::base::V1_0::DebugInfo info{};
        _hidl_cb(info);
    }
    return {};
}

STUB_ATTR
::android::hardware::Return<void>
IComposer::notifySyspropsChanged() { return {}; }

STUB_ATTR
::android::hardware::Return<bool>
IComposer::unlinkToDeath(const sp<ahw::hidl_death_recipient>& /*recipient*/) {
    return ::android::hardware::Return<bool>(true);
}

// ----------------------------------------------------------------------
// IComposerClient inherited IBase methods (exact typedef signatures)
// ----------------------------------------------------------------------

STUB_ATTR
::android::hardware::Return<void>
IComposerClient::interfaceChain(interfaceChain_cb _hidl_cb) {
    if (_hidl_cb) {
        ahw::hidl_vec<ahw::hidl_string> v;
        v.resize(0);
        _hidl_cb(v);
    }
    return {};
}

STUB_ATTR
::android::hardware::Return<void>
IComposerClient::debug(
    const ahw::hidl_handle& /*fd*/,
    const ahw::hidl_vec<ahw::hidl_string>& /*options*/) {
    return {};
}

STUB_ATTR
::android::hardware::Return<void>
IComposerClient::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) {
    if (_hidl_cb) _hidl_cb(ahw::hidl_string(""));
    return {};
}

STUB_ATTR
::android::hardware::Return<void>
IComposerClient::getHashChain(getHashChain_cb _hidl_cb) {
    if (_hidl_cb) {
        ahw::hidl_vec<ahw::hidl_array<uint8_t, 32>> hashes;
        hashes.resize(0);
        _hidl_cb(hashes);
    }
    return {};
}

STUB_ATTR
::android::hardware::Return<void>
IComposerClient::setHALInstrumentation() { return {}; }

STUB_ATTR
::android::hardware::Return<bool>
IComposerClient::linkToDeath(
    const ::android::sp<ahw::hidl_death_recipient>& /*recipient*/,
    uint64_t /*cookie*/) {
    return ::android::hardware::Return<bool>(false);
}

STUB_ATTR
::android::hardware::Return<void>
IComposerClient::ping() { return {}; }

STUB_ATTR
::android::hardware::Return<void>
IComposerClient::getDebugInfo(getDebugInfo_cb _hidl_cb) {
    if (_hidl_cb) {
        ::android::hidl::base::V1_0::DebugInfo info{};
        _hidl_cb(info);
    }
    return {};
}

STUB_ATTR
::android::hardware::Return<void>
IComposerClient::notifySyspropsChanged() { return {}; }

STUB_ATTR
::android::hardware::Return<bool>
IComposerClient::unlinkToDeath(
    const ::android::sp<ahw::hidl_death_recipient>& /*recipient*/) {
    return ::android::hardware::Return<bool>(false);
}

#undef STUB_ATTR

} // namespace V2_1
} // namespace composer
} // namespace graphics
} // namespace hardware
} // namespace android

// Factory symbol the HIDL loader looks up via dlsym()
extern "C" __attribute__((used,visibility("default")))
composer21::IComposer* HIDL_FETCH_IComposer(const char* /*name*/) {
    static composer21::ComposerStub kStub;
    return &kStub;
}

// Extra symbol you can reference from your binary to prevent the linker dropping the .so
extern "C" __attribute__((used,visibility("default")))
void composer21_stub_keepalive() {}
