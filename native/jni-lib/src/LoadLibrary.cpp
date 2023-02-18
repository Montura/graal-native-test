#include <sstream>
#include <iostream>
#include <jni.h>

#include "api/utils/LoadLibrary.h"

#if _MSC_VER && !__INTEL_COMPILER
#include <Windows.h>
#include <codecvt>

const wchar_t JAVA_DLL_NAME[] = L"java.dll";
const wchar_t JVM_DLL_NAME[] = L"jvm.dll";

std::wstring utf8_decode(const char* str) {
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str);
}

std::wstring javaLibraryPath(const char* javaHome) {
  auto java_home = utf8_decode(javaHome);
  return java_home + JAVA_DLL_NAME;
}

std::string jvmLibraryPath(const char* javaHome) {
  auto java_home = utf8_decode(javaHome);
  return java_home + JVM_DLL_NAME;
}

HINSTANCE openLib(const char* path) {
  HINSTANCE libraryHandle = LoadLibraryW(path);
  if (!libraryHandle) {
    std::cerr << "Can't load lib from: " << path << "\n";
  }
  std::cout << "Loaded library: " << path << "\n";
  return libraryHandle;
}

template <typename SymbolType, typename Handle>
SymbolType loadSymbol(HINSTANCE libraryHandle, const char* symbolName) {
  auto symbol = (SymbolType) GetProcAddress(libraryHandle, symbolName);
  if (!symbol) {
    std::string errMsg("Can't load lib from: ");
    throw std::runtime_error(errMsg + symbolName);
  }
  return symbol;
}
#else

#include <dlfcn.h>
#include <string>

template <class TargetType, class InitialType>
constexpr inline TargetType r_cast(InitialType arg) {
  return reinterpret_cast<TargetType>(arg);
}

const char JAVA_DLL_NAME[] = "/lib/libjava.dylib";
const char JVM_DLL_NAME[] = "/lib/server/libjvm.dylib";

std::string javaLibraryPath(const char* javaHome) {
  std::string java_home(javaHome);
  return java_home + JAVA_DLL_NAME;
}

std::string jvmLibraryPath(const char* javaHome) {
  std::string java_home(javaHome);
  return java_home + JVM_DLL_NAME;
}

void* openLib(const char* path) {
  void* libraryHandle = dlopen(path, RTLD_LAZY);
  if (!libraryHandle) {
    std::string errMsg("Can't load lib from: ");
    throw std::runtime_error(errMsg + path);
  }
  std::cout << "Loaded library: " << path << "\n";
  return libraryHandle;
}

template <typename SymbolType>
SymbolType loadSymbol(void* libraryHandle, const char* symbolName) {
  auto symbol = (SymbolType) dlsym(libraryHandle, symbolName);
  if (!symbol) {
    std::stringstream ss{};
    ss << "Can't load symbol" << symbolName << " from library:" << libraryHandle;
    throw std::runtime_error(ss.str());
  }
  return symbol;
}

#endif

namespace dxfeed::internal {
  CreateJavaVM_t createJavaVM = nullptr;

  void loadJVMLibrary(const char* javaHome) {
    auto javaDllPath = javaLibraryPath(javaHome);
    bool file_exists = fs::exists(javaDllPath);
    auto size = file_exists && fs::is_regular_file(javaDllPath) ? static_cast<int64_t>(fs::file_size(javaDllPath)) : 0;
    if (!size) {
      throw std::runtime_error("File don't exist: " + javaDllPath);
    }

    auto jvmDllPath = jvmLibraryPath(javaHome);
    auto JVM_DLL = openLib(jvmDllPath.c_str());
    createJavaVM = loadSymbol<CreateJavaVM_t>(JVM_DLL, "JNI_CreateJavaVM");
    auto findBootClass = loadSymbol<FindClassFromBootLoader_t>(JVM_DLL, "JVM_FindClassFromBootLoader");
    if (createJavaVM == nullptr || findBootClass == nullptr) {
      std::stringstream ss{};
      ss << "GetProcAddress failed: " << r_cast<void*>(createJavaVM) << ", " << r_cast<void*>(findBootClass);
      throw std::runtime_error(ss.str());
    }
  }
}

// todo: at least need
//      server/jvm.dll
//      java.dll
//      jimage.dll
//      jsvml.dll
//      verify.dll
//      lib/modules