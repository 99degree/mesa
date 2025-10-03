// log_stub.cpp
#include <cstdarg>
#include <android/log.h>

extern "C" {

__attribute__((used,visibility("default")))
int __android_log_print(int, const char*, const char*, ...) { return 0; }

__attribute__((used,visibility("default")))
int __android_log_vprint(int, const char*, const char*, va_list) { return 0; }

__attribute__((used,visibility("default")))
int __android_log_write(int, const char*, const char*) { return 0; }

__attribute__((used,visibility("default")))
void __android_log_assert(const char*, const char*, const char*, ...) {}

}
