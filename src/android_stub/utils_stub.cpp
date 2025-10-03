// utils_stub.cpp
// Stub libutils.so: export RefBase symbols with exact prototypes.
// Every method is marked used + default visibility to force emission.

#include <cstddef>
#include <cstdint>
#include <utils/RefBase.h>

namespace android {

// Constructor must initialize const member mRefs.
__attribute__((used,visibility("default")))
RefBase::RefBase() : mRefs(nullptr) {}

__attribute__((used,visibility("default")))
RefBase::~RefBase() {}

// Strong reference management
__attribute__((used,visibility("default")))
void RefBase::incStrong(const void* /*id*/) const {}

__attribute__((used,visibility("default")))
void RefBase::decStrong(const void* /*id*/) const {}

__attribute__((used,visibility("default")))
int32_t RefBase::getStrongCount() const { return 0; }

__attribute__((used,visibility("default")))
void RefBase::forceIncStrong(const void* /*id*/) const {}

__attribute__((used,visibility("default")))
void RefBase::incStrongRequireStrong(const void* /*id*/) const {}

// Weak reference management
__attribute__((used,visibility("default")))
RefBase::weakref_type* RefBase::createWeak(const void* /*id*/) const {
    return nullptr;
}

__attribute__((used,visibility("default")))
RefBase::weakref_type* RefBase::getWeakRefs() const {
    return nullptr;
}

// Lifetime control
__attribute__((used,visibility("default")))
void RefBase::extendObjectLifetime(int /*mode*/) {}

__attribute__((used,visibility("default")))
void RefBase::renameRefs(size_t /*n*/, const ReferenceRenamer& /*renamer*/) {}

__attribute__((used,visibility("default")))
void RefBase::renameRefId(weakref_type* /*wr*/, const void* /*old_id*/, const void* /*new_id*/) {}

__attribute__((used,visibility("default")))
void RefBase::renameRefId(RefBase* /*rb*/, const void* /*old_id*/, const void* /*new_id*/) {}

// Lifecycle hooks
__attribute__((used,visibility("default")))
void RefBase::onFirstRef() {}

__attribute__((used,visibility("default")))
void RefBase::onLastStrongRef(const void* /*id*/) {}

__attribute__((used,visibility("default")))
bool RefBase::onIncStrongAttempted(uint32_t /*flags*/, const void* /*id*/) { return false; }

__attribute__((used,visibility("default")))
void RefBase::onLastWeakRef(const void* /*id*/) {}

// Nested weakref_type methods
__attribute__((used,visibility("default")))
void RefBase::weakref_type::decWeak(const void* /*id*/) {}

} // namespace android

// LightRefBase failure reporter
extern "C" {
__attribute__((used,visibility("default")))
void android_LightRefBase_reportIncStrongRequireStrongFailed(const void* /*id*/) {}
}
