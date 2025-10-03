// fake_libcxx_stubs.cpp
// WARNING: These are dummy stubs to satisfy the linker only.
// Do not call them at runtime.

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

extern "C" {

// abort helper
void _ZNSt3__1__libcpp_verbose_abortEPKcz(const char*, ...) {
    fprintf(stderr, "called __libcpp_verbose_abort (stub)\n");
    __builtin_trap();
}

// shared_ptr internals
void _ZNSt3__118__shared_weak_count16__release_weakEv() {}
void _ZNSt3__118__shared_weak_countD1Ev() {}
void _ZNSt3__118__shared_weak_countD0Ev() {}
void _ZNSt3__118__shared_weak_count13__get_deleterERKSt9type_info() {}

// mutex/condition_variable/thread
void _ZNSt3__15mutexD1Ev() {}
void _ZNSt3__15mutexD0Ev() {}
void _ZNSt3__15mutex4lockEv() {}
void _ZNSt3__15mutex6unlockEv() {}

void _ZNSt3__118condition_variableD1Ev() {}
void _ZNSt3__118condition_variableD0Ev() {}
void _ZNSt3__118condition_variable10notify_allEv() {}
void _ZNSt3__118condition_variable4waitERNS_11unique_lockINS_5mutexEEE() {}

void _ZNSt3__16threadD1Ev() {}
void _ZNSt3__16threadD0Ev() {}
void _ZNSt3__16thread4joinEv() {}
void _ZNSt3__16thread6detachEv() {}

void _ZNSt3__1L12__call_onceERVmPvPFvS2_E(void) {}

} // extern "C"

// You can add more stubs as needed for the specific mangled names

// c++_shared_stub.cpp
// WARNING: This is a fake stub. It only satisfies the linker.
// Any actual use of std::string, streams, threads, etc. will crash.

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

extern "C" {

// Example stubs for common libc++ symbols you saw missing:

// verbose abort
void _ZNSt3__1L20__libcpp_verbose_abortEPKcz(const char*, ...) {
    fprintf(stderr, "stub: __libcpp_verbose_abort called\n");
}

// string destructor
void _ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev() {}
void _ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev() {}

// string init
void _ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm() {}

// to_string overloads
const char* _ZNSt3__1L8to_stringEi(int) { return "0"; }
const char* _ZNSt3__1L8to_stringEj(unsigned int) { return "0"; }
const char* _ZNSt3__1L8to_stringEm(unsigned long) { return "0"; }

// chrono::steady_clock::now
long long _ZNSt3__18chrono12steady_clock3nowEv() { return 0; }

// throw system_error
void _ZNSt3__1L20__throw_system_errorEiPKc(int, const char*) {
    fprintf(stderr, "stub: __throw_system_error called\n");
}

// next_prime
unsigned long _ZNSt3__1L12__next_primeEm(unsigned long) { return 2; }

} // extern "C"

// For vtables, you can declare weak dummy objects:
namespace std {
namespace __1 {

struct __fake_base { virtual ~__fake_base() {} };
struct __fake_stringbuf : __fake_base {};
struct __fake_ios : __fake_base {};
struct __fake_ostringstream : __fake_ios {};

__fake_stringbuf __fake_stringbuf_vtable;
__fake_ios __fake_ios_vtable;
__fake_ostringstream __fake_ostringstream_vtable;

} // namespace __1
} // namespace std
