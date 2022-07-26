#include <cstdio>
#include <ctime>
#include "graal/graal_isolate.h"

#ifdef _WIN64
  #include <windows.h>

  const wchar_t* GRAAL_LIB_NAME = L"GraalSample";
  const char* SYMBOL_TEST = "test";
  const char* SYMBOL_TEST_C = "testC";

  typedef void(*test_ptr)(graal_isolatethread_t*);
  typedef int(*test_c_ptr)();

  void test_ptr_and_log(const char* symbol_name, void* func_ptr) {
    if (func_ptr) {
      printf("Symbol \"%s\" is found in GraalSample.dll, addr = %p \n", symbol_name, func_ptr);
    } else {
      printf("Symbol \"%s\" isn't found in GraalSample.dll, addr = %p \n", symbol_name, func_ptr);
    }
  }

  void testLib() {
    HMODULE handle = GetModuleHandleW(GRAAL_LIB_NAME);
    if (handle) {
      test_ptr test_func_ptr = (test_ptr)GetProcAddress(handle, SYMBOL_TEST);
      test_ptr_and_log(SYMBOL_TEST, test_func_ptr);

      test_c_ptr test_c_func_ptr = (test_c_ptr)GetProcAddress(handle, SYMBOL_TEST_C);
      test_ptr_and_log(SYMBOL_TEST_C, test_c_func_ptr);
      HRESULT hr = FreeLibrary(handle);
    }
  }

#endif 


extern "C" void test(graal_isolatethread_t*);
extern "C" int testC();


int main() {
    graal_isolate_t* isolate;
    graal_isolatethread_t* thread;
    graal_create_isolate(nullptr, &isolate, &thread);
#ifdef _WIN64
    testLib();
#endif()
    test(thread);

    int n = 10000000;
    for (int i = 0; i < n; i++) {
        testC();
    }
    timespec time1;
    timespec_get(&time1, TIME_UTC);
    for (int i = 0; i < n; i++) {
        testC();
    }
    timespec time2;
    timespec_get(&time2, TIME_UTC);
    printf("native time = %ld\n", ((time2.tv_sec - time1.tv_sec) * 1000000000 + (time2.tv_nsec - time1.tv_nsec)) / n);
}