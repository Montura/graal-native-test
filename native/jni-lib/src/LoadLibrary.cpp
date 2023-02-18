#include <iostream>
#include <filesystem>
#include <jni.h>

#if _MSC_VER && !__INTEL_COMPILER
#include <Windows.h>
#include <codecvt>
#else

#include <dlfcn.h>
#include <string>

#endif

#include "api/utils/LoadLibrary.h"

namespace fs = std::filesystem;

// todo: at least need
//      server/jvm.dll
//      java.dll
//      jimage.dll
//      jsvml.dll
//      verify.dll
//      lib/modules

namespace dxfeed::internal {
  CreateJavaVM_t createJavaVM = nullptr;

#if _MSC_VER && !__INTEL_COMPILER
  // todo: replace with platform code
      std::wstring utf8_decode(const char* str) {
          return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str);
      }
#endif

  // todo: extract platform specific
  void loadJVMLibrary(const char* javaHome) {
#if _MSC_VER && !__INTEL_COMPILER
    std::wstring java_home = utf8_decode(javaHome);
    auto javaDllPath = java_home + L"\\bin\\java.dll";
    bool file_exists = fs::exists(javaDllPath);
    auto size = file_exists && fs::is_regular_file(javaDllPath) ? static_cast<int64_t>(fs::file_size(javaDllPath)) : 0;
    if (!size) {
        std::cerr << "File don't exist: " << javaDllPath.c_str() << "\n";
    }

    auto jvmDllPath = java_home + L"/bin/server/jvm.dll";
    HINSTANCE JVM_DLL = LoadLibraryW(jvmDllPath.c_str());
    if (!JVM_DLL) {
        std::cerr << "Can't load lib from: " << jvmDllPath.c_str() << "\n";
        return;
    }

    createJavaVM = (CreateJavaVM_t) GetProcAddress(JVM_DLL, "JNI_CreateJavaVM");
    findBootClass = (FindClassFromBootLoader_t) GetProcAddress(JVM_DLL, "JVM_FindClassFromBootLoader");
    if (createJavaVM == nullptr || findBootClass == nullptr) {
        std::cout << "GetProcAddress failed: "
                  << reinterpret_cast<void*>(createJavaVM) << ", " << reinterpret_cast<void*>(findBootClass)
                  << "\n";
    }
#endif
    std::string java_home(javaHome);
    auto javaDllPath = java_home + "/lib/libjava.dylib";
    bool file_exists = fs::exists(javaDllPath);
    auto size = file_exists && fs::is_regular_file(javaDllPath) ? static_cast<int64_t>(fs::file_size(javaDllPath)) : 0;
    if (!size) {
      std::cerr << "File don't exist: " << javaDllPath.c_str() << "\n";
      return;
    }

    auto jvmDllPath = java_home + "/lib/server/libjvm.dylib";
    void* JVM_DLL = dlopen(jvmDllPath.c_str(), RTLD_LAZY);
    if (!JVM_DLL) {
      std::cerr << "Can't load lib from: " << jvmDllPath.c_str() << "\n";
      return;
    }
    std::cout << "Loaded: " << jvmDllPath.c_str() << "\n";
    createJavaVM = (CreateJavaVM_t) dlsym(JVM_DLL, "JNI_CreateJavaVM");
    auto findBootClass = (FindClassFromBootLoader_t) dlsym(JVM_DLL, "JVM_FindClassFromBootLoader");
    if (createJavaVM == nullptr || findBootClass == nullptr) {
      std::cout << "GetProcAddress failed: "
                << reinterpret_cast<void*>(createJavaVM) << ", " << reinterpret_cast<void*>(findBootClass)
                << "\n";
    }
  }
}