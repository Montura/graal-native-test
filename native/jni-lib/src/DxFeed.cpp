#include <stdexcept>
#include "api/DxFeed.h"
#include "api/Connection.h"
#include "api/utils/LoadLibrary.h"

namespace dxfeed {
  void dxfeed::DxFeed::initJavaVM(const char* javaHome) {
    dxfeed::internal::loadJavaVM(javaHome);
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
//    auto path = "D:\\work\\graal-native-test\\native\\cmake-build-debug\\native_jni.dll";
    auto path = "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/native/cmake-build-debug/native_jni.dylib";
    loadJNILibrary(path);
  }

  void DxFeed::loadJNILibrary(const char* path) {
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
