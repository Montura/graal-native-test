#include <stdexcept>
#include "api/DxFeed.h"
#include "api/Connection.h"

namespace dxfeed {
  void dxfeed::DxFeed::initJavaVM(const char* javaHome) {
#if _MSC_VER && !__INTEL_COMPILER
    dxfeed::DxFeed::loadVm(javaHome);
#elif 0
    std::unique_ptr <JavaVMOption> javaVmOption(new JavaVMOption);
//      javaVmOption->optionString = const_cast<char*>(QD_CLASS_PATH.c_str());
      javaVmOption->optionString = const_cast<char*>("-Xbootclasspath:[bootJar]");

      JavaVMInitArgs vmArgs;
      vmArgs.version = JNI_VERSION_1_8;
      vmArgs.nOptions = 1;
      vmArgs.options = javaVmOption.get();
      vmArgs.ignoreUnrecognized = JNI_TRUE;

      // Create the JVM
      long flag = 0;;//JNI_CreateJavaVM(&javaVM, (void**) &jniEnv, &vmArgs);
      if (flag == JNI_ERR) {
        throw std::runtime_error("Error creating VM. Exiting...n");
      }
#else

#endif
  }

  // todo: add dispose!!!!!!!!!!!!!
  void disposeJavaVM() {
    javaVM->DestroyJavaVM();
  }

  DxFeed& dxfeed::DxFeed::getInstance() {
    static DxFeed instance;
    return instance;
  }

  DxFeed::DxFeed() :
      env_{jniEnv},
      timeAndSalesMapper_{env_, onClose},
      listMapper_{env_, onClose},
      javaHelperClass{jniEnv->FindClass("Lcom/dxfeed/api/JniTest;")},
      addEventListenerHelperMethodId{jniEnv->GetStaticMethodID(javaHelperClass, "addEventListener",
                                                               "(Lcom/dxfeed/api/DXFeedSubscription;J)V")} {
    auto path = "D:\\work\\graal-native-test\\native\\cmake-build-debug\\native_jni.dll";
    //  auto path = "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/native/jni-lib/bin/native_jni.dylib";
    loadLibrary(path);
  }

  void DxFeed::loadLibrary(const char* path) {
    jmethodID methodId = jniEnv->GetStaticMethodID(javaHelperClass, "loadJNILib", "(Ljava/lang/String;)V");
    jstring pJstring = jniEnv->NewStringUTF(path);
    jniEnv->CallStaticVoidMethod(javaHelperClass, methodId, pJstring);
  }

  jclass DxFeed::helperClass() {
    return javaHelperClass;
  }

  jmethodID DxFeed::addEventListenerMethod() {
    return addEventListenerHelperMethodId;
  }

  const TimeAndSaleMapper& DxFeed::getTimeAndSaleMapper() {
    return timeAndSalesMapper_;
  }

  const ListMapper& DxFeed::getListMapper() {
    return listMapper_;
  }

  void DxFeed::onClose(jobject clazz) {
    jniEnv->DeleteGlobalRef(clazz);
  }

  Connection* DxFeed::createConnection(const std::string& address) {
    return new Connection(env_, address, onClose);
  }
}
