#include <cstdio>
#include "graal_isolate.h"

const wchar_t* GRAAL_LIB_NAME = L"GraalSample";
const char* SYMBOL_TEST = "test";
const char* SYMBOL_TEST_C = "testC";

typedef void(*test_ptr)(graal_isolatethread_t*);
typedef int(*test_c_ptr)();

test_ptr get_test_ptr();
test_c_ptr get_test_c_ptr();

void test_ptr_and_log(const char* symbol_name, void* func_ptr) {
    if (func_ptr) {
        printf("Symbol \"%s\" is found in GraalSample.* shared library, addr = %p \n", symbol_name, func_ptr);
    } else {
        printf("Symbol \"%s\" isn't found in GraalSample.* shared library, addr = %p \n", symbol_name, func_ptr);
    }
}

#ifdef _WIN64
    #include <Windows.h>

    struct Lib {
        Lib() : handle(GetModuleHandleW(GRAAL_LIB_NAME)) {}
        ~Lib() {
            if (handle) {
                HRESULT hr = FreeLibrary(handle);
                if (FAILED(hr)) {
                    printf("Error on closing shared lib!");
                }
            }
        }
        const HMODULE handle;
    };

    test_ptr get_test_ptr() {
        Lib lib;
        return lib.handle ? (test_ptr)GetProcAddress(lib.handle, SYMBOL_TEST) : nullptr;
    }

    test_c_ptr get_test_c_ptr() {
        Lib lib;
        return lib.handle ? (test_c_ptr)GetProcAddress(lib.handle, SYMBOL_TEST_C) : nullptr;
    }

#else

    #include <dlfcn.h>
    #ifndef RTLD_DEFAULT
        #define RTLD_DEFAULT 0
    #endif

    test_ptr get_test_ptr() {
        return (test_ptr) dlsym(RTLD_DEFAULT, SYMBOL_TEST);
    }

    test_c_ptr get_test_c_ptr() {
        return (test_c_ptr) dlsym(RTLD_DEFAULT, SYMBOL_TEST_C);
    }
#endif

void testLib() {
    auto test_func_ptr = get_test_ptr();
    test_ptr_and_log(SYMBOL_TEST, (void*)test_func_ptr);

    auto test_c_func_ptr = get_test_c_ptr();
    test_ptr_and_log(SYMBOL_TEST_C, (void*)test_c_func_ptr);
}
