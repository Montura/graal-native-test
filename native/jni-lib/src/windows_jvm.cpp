#if _MSC_VER && !__INTEL_COMPILER
  #include <Windows.h>
#else
  #include <dlfcn.h>
#endif
#include <iostream>
#include <filesystem>
#include <jni.h>
#include <string>
#include <codecvt>

#include "api/DxFeed.h"

namespace fs = std::filesystem;

// todo: at least need
//      server/jvm.dll
//      java.dll
//      jimage.dll
//      jsvml.dll
//      verify.dll
//      lib/modules
//constexpr wchar_t JAVA_HOME[] = L"" JAVA_HOME_PATH; // get JAVA_HOME from

typedef jint(JNICALL *CreateJavaVM_t)(JavaVM **pvm, void **env, void *args);
typedef jclass(JNICALL *FindClassFromBootLoader_t)(JNIEnv *env, const char *name);

namespace dxfeed {
    JNIEnv* jniEnv = nullptr;
    JavaVM* javaVM = nullptr;

    void loadVM(CreateJavaVM_t createJavaVM) {
        JavaVMOption options[1];
        options[0].optionString =
          "-Djava.class.path=/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/graal-tutorial-1.1-SNAPSHOT.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/auther-api-442.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/dxfeed-api-3.313.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/dxlib-3.313.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/qds-3.313.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/qds-file-3.313.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/qds-tools-3.313.jar";


        JavaVMInitArgs vmArgs;
        vmArgs.version = JNI_VERSION_1_8;
        vmArgs.options = options;
        vmArgs.nOptions = 1;
        vmArgs.ignoreUnrecognized = JNI_FALSE;

        // Create the JVM
        jint flag = createJavaVM(&javaVM, (void**) &jniEnv, &vmArgs);
        if (flag == JNI_ERR) {
            throw std::runtime_error("Error creating VM. Exiting...n");
        }
    }

#if _MSC_VER && !__INTEL_COMPILER
// todo: replace with platform code
    std::wstring utf8_decode(const char* str) {
        return std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(str);
    }
#endif
    // todo: extract platform specific
    void DxFeed::loadVm(const char* javaHome) {
        CreateJavaVM_t createJavaVM;
        FindClassFromBootLoader_t findBootClass;

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
      }

      auto jvmDllPath = java_home + "/lib/server/libjvm.dylib";
      void* JVM_DLL = dlopen(jvmDllPath.c_str(), RTLD_LAZY);
      if (!JVM_DLL) {
        std::cerr << "Can't load lib from: " << jvmDllPath.c_str() << "\n";
        return;
      }
      std::cout << "Loaded: " << jvmDllPath.c_str() << "\n";
      createJavaVM = (CreateJavaVM_t) dlsym(JVM_DLL, "JNI_CreateJavaVM");
      findBootClass = (FindClassFromBootLoader_t) dlsym(JVM_DLL, "JVM_FindClassFromBootLoader");
      if (createJavaVM == nullptr || findBootClass == nullptr) {
        std::cout << "GetProcAddress failed: "
                  << reinterpret_cast<void*>(createJavaVM) << ", " << reinterpret_cast<void*>(findBootClass)
                  << "\n";
      }
      loadVM(createJavaVM);
    }
}