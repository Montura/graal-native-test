#include <jni.h>
#include <string>
#include <iostream>

#include "api/utils/LoadLibrary.h"

namespace dxfeed {
  JNIEnv* jniEnv = nullptr;
  JavaVM* javaVM = nullptr;

  namespace internal {
    constexpr char PATH_SEPARATOR = ':';
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
      auto jarPath = runtimePath.parent_path().parent_path().string() + "/target/";
      auto jarDxFeedPath = jarPath + "/libs/";
      std::cout << "Custom JAR path: " <<  jarPath << std::endl;
      std::cout << "DxFeed JAR path: " <<  jarPath << std::endl;

      std::string result = jarPath + MY_JAR + PATH_SEPARATOR;
      for (const auto jar : JARS) {
        result += jarDxFeedPath + jar + PATH_SEPARATOR;
      }
      auto path = "-Djava.class.path=" + result.substr(0, result.size() - 1);
      std::cout << "classpath: " << path;
      return path;
    }

    void loadJNILibrary(const char* path) {
      jclass pJclass = jniEnv->FindClass("Ljava/lang/System;");
      std::cout << "java.lang.System: " << pJclass << "\n";
      jmethodID methodId = jniEnv->GetStaticMethodID(pJclass, "load", "(Ljava/lang/String;)V");
      std::cout << "void System::load(String path): " << methodId << "\n";

      jstring pJstring = jniEnv->NewStringUTF(path);
      jniEnv->CallStaticVoidMethod(pJclass, methodId, pJstring);
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

      auto path = runtimePath.string() + "/native_jni.dylib";
      loadJNILibrary(path.c_str());
    }

    // todo: add dispose!!!!!!!!!!!!!
    void disposeJavaVM() {
      javaVM->DestroyJavaVM();
    }
  }
}