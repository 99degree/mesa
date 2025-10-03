#if __ANDROID_API__ > 34

// hidl_log_stub.cpp
#include <string>
#include <iostream>

namespace android {
namespace hardware {
namespace details {

void logError(const std::string& msg) {
    // Stub: print to stderr or ignore
    std::cerr << "[stub logError] " << msg << std::endl;
}

} // namespace details
} // namespace hardware
} // namespace android
#endif
// Canary / test symbol
extern "C" {

// Forward declare hw_module_t so we don’t need <hardware/hardware.h>
struct hw_module_t;

int fmq_dummy_hw_get_module(const char * /*id*/, const struct hw_module_t ** /*module*/) {
    return 0;
}

} // extern "C"
