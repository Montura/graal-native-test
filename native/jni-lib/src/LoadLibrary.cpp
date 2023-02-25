#include <sstream>
#include <iostream>

#include "api/utils/LoadLibrary.h"

#if _MSC_VER && !__INTEL_COMPILER
#include <Windows.h>
#include <codecvt>

const wchar_t JAVA_DLL_NAME[] = L"java.dll";
const wchar_t JVM_DLL_NAME[] = L"jvm.dll";

std::wstring utf8_decode(const char* str) {
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str);
}

template <typename SymbolType>
SymbolType loadSymbolPlatform(HINSTANCE libraryHandle, const char* symbolName) {
  return (SymbolType) GetProcAddress(libraryHandle, symbolName);
}

auto loadLibraryPlatform(const wchar_t* symbolName) {
  return LoadLibraryW(symbolName);
}
#else

#include <dlfcn.h>
#include <string>

const char JAVA_DLL_NAME[] = "libjava.dylib";
const char JVM_DLL_NAME[] = "libjvm.dylib";

std::string utf8_decode(const char* str) {
  return std::string { str };
}

auto loadLibraryPlatform(const char* path) {
  return dlopen(path, RTLD_LAZY);
}

template <typename SymbolType>
SymbolType loadSymbolPlatform(void* libraryHandle, const char* symbolName) {
  return (SymbolType) dlsym(libraryHandle, symbolName);
}

#endif

template <class TargetType, class InitialType>
constexpr inline TargetType r_cast(InitialType arg) {
  return reinterpret_cast<TargetType>(arg);
}

template <typename CharT>
fs::path recursivelyLookUpLibraryByName(const fs::path& path, CharT libName) {
  for (const auto& dirOrFile : fs::directory_iterator(path)) {
    if (dirOrFile.is_directory()) {
      for (const auto& file : fs::directory_iterator(dirOrFile)) {
        if (file.is_regular_file() && file.path().filename() == libName) {
          return file.path();
        } else if (file.is_directory()) {
          return recursivelyLookUpLibraryByName(file, libName);
        }
      }
    } else if (dirOrFile.is_regular_file() && dirOrFile.path().filename() == libName) {
      return dirOrFile.path();
    }
  }
  return fs::path {"NO_PATH"};
}

auto loadLibrary(const fs::path& path) {
  auto libraryHandle = loadLibraryPlatform(path.c_str());
  if (!libraryHandle) {
    std::string errMsg("Can't load lib from: ");
    throw std::runtime_error(errMsg + path.string());
  }
  std::cout << "Loaded library: " << path << "\n";
  return libraryHandle;
}

template<typename SymbolType, typename HandleT>
SymbolType loadSymbol(HandleT libraryHandle, const char* symbolName) {
  auto symbol = loadSymbolPlatform<SymbolType>(libraryHandle, symbolName);
  if (!symbol) {
    std::string errMsg("Can't load symbol: ");
    throw std::runtime_error(errMsg + symbolName);
  }
  return symbol;
}

namespace dxfeed::internal {
  CreateJavaVM_t createJavaVM = nullptr;

  void loadJVMLibrary(const char* java_home_utf8) {
    auto javaHome = utf8_decode(java_home_utf8);

    auto javaDllPath = recursivelyLookUpLibraryByName(javaHome, JAVA_DLL_NAME);
    bool file_exists = fs::exists(javaDllPath);
    auto size = file_exists && fs::is_regular_file(javaDllPath) ? static_cast<int64_t>(fs::file_size(javaDllPath)) : 0;
    if (!size) {
      throw std::runtime_error(javaDllPath.string() + "doesn't exits");
    }

    auto jvmDllPath = recursivelyLookUpLibraryByName(javaHome, JVM_DLL_NAME);
    auto JVM_DLL = loadLibrary(jvmDllPath.c_str());
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