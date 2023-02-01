#include "api/DxFeed.h"
#include "api/Connection.h"
#include "classpath.h"

namespace dxfeed {
  static JNIEnv* jniEnv;
  static JavaVM* javaVM;

  void initJavaVMAndJNI() {
    if (!jniEnv && !javaVM) {
      std::unique_ptr <JavaVMOption> javaVmOption(new JavaVMOption);
      javaVmOption->optionString = const_cast<char*>(QD_CLASS_PATH.c_str());

      JavaVMInitArgs vmArgs;
      vmArgs.version = JNI_VERSION_1_8;
      vmArgs.nOptions = 1;
      vmArgs.options = javaVmOption.get();
      vmArgs.ignoreUnrecognized = JNI_TRUE;

      // Create the JVM
      long flag = JNI_CreateJavaVM(&javaVM, (void**) &jniEnv, &vmArgs);
      if (flag == JNI_ERR) {
        throw std::runtime_error("Error creating VM. Exiting...n");
      }
    }
  }

  // todo: add dispose!!!!!!!!!!!!!
  void disposeJavaVM() {
    javaVM->DestroyJavaVM();
  }

  DxFeed& dxfeed::DxFeed::getInstance() {
    initJavaVMAndJNI();
    static DxFeed instance;
    return instance;
  }

  DxFeed::DxFeed() :
    env_{jniEnv},
    timeAndSalesMapper_{env_, onClose},
    listMapper_{env_, onClose} {
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
