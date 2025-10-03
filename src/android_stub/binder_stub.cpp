namespace android {

namespace base {
    enum LogSeverity { VERBOSE, DEBUG, INFO, WARNING, ERROR, FATAL };
    bool ShouldLog(LogSeverity, const char*) { return false; }
}

} // namespace android

// binder_stub.cpp (additions)

namespace android {

class ProcessState {
public:

__attribute__((used, visibility("default")))
    // Stub for initWithDriver
    static void initWithDriver(const char* /*driver*/) {
        // no-op
    }

__attribute__((used, visibility("default")))
    // Stub for self()
    static ProcessState* self() {
        static ProcessState instance;
        return &instance;
    }

__attribute__((used, visibility("default")))
    // Stub for setThreadPoolMaxThreadCount
    void setThreadPoolMaxThreadCount(unsigned long /*count*/) {
        // no-op
    }

__attribute__((used, visibility("default")))
    // Stub for startThreadPool
    void startThreadPool() {
        // no-op
    }
};

} // namespace android
