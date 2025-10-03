#include <string>
#include <mutex>
#include <condition_variable>
#include <thread>

namespace std::__1 {

// mutex
mutex::~mutex() {}
void mutex::lock() {}
void mutex::unlock() {}

// condition_variable
condition_variable::~condition_variable() {}
void condition_variable::notify_all() {}
void condition_variable::wait(unique_lock<mutex>&) {}

// thread
thread::~thread() {}
void thread::join() {}
__thread_struct::__thread_struct() {}

// string
basic_string<char, char_traits<char>, allocator<char>>::~basic_string() {}

// to_string
std::string to_string(unsigned int v) {
    return "[stub:" + std::to_string((unsigned long long)v) + "]";
}

void __libcpp_verbose_abort(const char*, ...) {}
void __throw_system_error(int, const char*) {}

} // namespace std::__1
