// fmq_eventflag_stub.cpp
#include <atomic>
#include <cstdint>

namespace android {
    using status_t = int;
    constexpr status_t NO_ERROR = 0;
    constexpr status_t BAD_VALUE = -22;
}

namespace android {
namespace hardware {

struct EventFlag {
    // Declarations only here
    static ::android::status_t createEventFlag(std::atomic<uint32_t>* efWordPtr,
                                               EventFlag** ef);
    static ::android::status_t deleteEventFlag(EventFlag** ef);
};

// Out‑of‑line definitions so they are emitted into the object file
::android::status_t EventFlag::createEventFlag(std::atomic<uint32_t>* /*efWordPtr*/,
                                               EventFlag** ef) {
    if (!ef) return ::android::BAD_VALUE;
    static EventFlag singleton;
    *ef = &singleton;
    return ::android::NO_ERROR;
}

::android::status_t EventFlag::deleteEventFlag(EventFlag** ef) {
    if (!ef || !*ef) return ::android::BAD_VALUE;
    *ef = nullptr; // pretend we deleted it
    return ::android::NO_ERROR;
}

} // namespace hardware
} // namespace android

// Canary / test symbol
extern "C" {

// Forward declare hw_module_t so we don’t need <hardware/hardware.h>
struct hw_module_t;

int dummy_hw_get_module(const char * /*id*/, const struct hw_module_t ** /*module*/) {
    return 0;
}

} // extern "C"
