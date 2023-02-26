#include <jni.h>
#include <string>
#include <iostream>

#include "api/utils/LoadLibrary.h"
#include "api/utils/JavaProperty.h"

namespace dxfeed {
  JNIEnv* jniEnv = nullptr;
  JavaVM* javaVM = nullptr;

  namespace internal {
#if _MSC_VER && !__INTEL_COMPILER
    constexpr char JAR_SEPARATOR = ';';
    const char PATH_SEPARATOR = '\\';
    const char JNI_LIB_NAME[] = "native_jni.dll";
#else
    constexpr char JAR_SEPARATOR = ':';
    constexpr char PATH_SEPARATOR = '/';
    const char JNI_LIB_NAME[] = "native_jni.dylib";
#endif
    const char MY_JAR[] = "graal-tutorial-1.1-SNAPSHOT.jar";
    const char* JARS[] = {
      "auther-api-442.jar",
      "dxfeed-api-3.313.jar",
      "dxlib-3.313.jar",
      "qds-3.313.jar",
      "qds-file-3.313.jar",
      "qds-tools-3.313.jar"
    };

    std::string buildClassPath(const std::filesystem::path& runtimePath) {
      auto jarPath = runtimePath.parent_path().parent_path().append("target");
      auto jarDxFeedPath = absolute(jarPath).append("libs").string();
      std::cout << "Custom JAR path: " <<  jarPath << std::endl;
      std::cout << "DxFeed JAR path: " <<  jarDxFeedPath << std::endl;

      std::filesystem::path result = jarPath.string() + PATH_SEPARATOR + MY_JAR;
      for (const auto jar : JARS) {
        result +=  JAR_SEPARATOR + jarDxFeedPath + jar;
      }
      auto path = "-Djava.class.path=" + result.string();
      std::cout << "classpath: " << path << std::endl;
      return path;
    }

    void dumpJavaInfo(jclass pJclass, jmethodID methodId) {
      auto vendor = JavaProperty { pJclass, methodId, "java.vendor"};
      auto version = JavaProperty { pJclass, methodId, "java.version"};
      auto versionDate = JavaProperty { pJclass, methodId, "java.version.date"};
      auto runtimeName = JavaProperty { pJclass, methodId, "java.runtime.name"};
      auto runtimeVersion = JavaProperty { pJclass, methodId, "java.runtime.version"};
      auto vmName = JavaProperty { pJclass, methodId, "java.vm.name"};
      auto vmVendor = JavaProperty { pJclass, methodId, "java.vm.vendor"};
      auto vmVersion = JavaProperty { pJclass, methodId, "java.vm.version"};
      auto vmInfo = JavaProperty { pJclass, methodId, "java.vm.info"};

      std::cout << "JAVA_HOME info:" << std::endl;
      std::cout << "\t" << vendor << " version \"" << version << "\" " << versionDate << std::endl;
      std::cout << "\t" << runtimeName << " (build " << runtimeVersion << ")" << std::endl;
      std::cout << "\t" << vmName << " " << vmVendor << " (build" << vmVersion << ", " << vmInfo << ")" << std::endl;
    }

    void loadJNILibrary(const char* path) {
      jclass javaLangSystemClazz = jniEnv->FindClass("Ljava/lang/System;");
      std::cout << "java.lang.System: " << javaLangSystemClazz << "\n";
      jmethodID loadMethodId = jniEnv->GetStaticMethodID(javaLangSystemClazz, "load", "(Ljava/lang/String;)V");
      std::cout << "void System::load(String path): " << loadMethodId << "\n";
      jstring pJstring = jniEnv->NewStringUTF(path);
      jniEnv->CallStaticVoidMethod(javaLangSystemClazz, loadMethodId, pJstring);

      jmethodID getPropMethodId = jniEnv->GetStaticMethodID(javaLangSystemClazz, "getProperty", "(Ljava/lang/String;)Ljava/lang/String;");
      std::cout << "void System::getProperty(String path): " << getPropMethodId << "\n";
      dumpJavaInfo(javaLangSystemClazz, getPropMethodId);

      jclass clazz = jniEnv->FindClass("com/dxfeed/api/JniTest");
      std::cout << "\tclazz com/dxfeed/api/JniTest: " << clazz << std::endl;

      jint res = jniEnv->RegisterNatives(clazz, methods, sizeof(methods)/sizeof(methods[0]));
      auto msg = (res == JNI_OK) ? "JNI_OK" : "Failed";
      std::cout << "\tRegisterNatives result: " << msg << "(" << res << ")" << std::endl;
    }

    void loadJavaVM(const char* javaHome) {
      internal::loadJVMLibrary(javaHome);

      auto runtimePath = fs::current_path();
      std::cout << "APP_RUNTIME_PATH: " <<  runtimePath << std::endl;

      JavaVMOption options[1];
      std::string string = buildClassPath(runtimePath);
      options[0].optionString = string.data();

      JavaVMInitArgs vmArgs;
      vmArgs.version = JNI_VERSION_1_8;
      vmArgs.options = options;
      vmArgs.nOptions = 1;
      vmArgs.ignoreUnrecognized = JNI_FALSE;

      // Create the JVM
      jint flag = internal::createJavaVM(&javaVM, (void**) &jniEnv, &vmArgs);
      if (flag == JNI_ERR) {
        throw std::runtime_error("Error creating VM. Exiting...n");
      }

      auto path = runtimePath.string() + PATH_SEPARATOR + JNI_LIB_NAME;
      loadJNILibrary(path.c_str());
    }

    // todo: add dispose!!!!!!!!!!!!!
    void disposeJavaVM() {
      javaVM->DestroyJavaVM();
    }
  }
}