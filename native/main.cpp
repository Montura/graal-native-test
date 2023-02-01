#include <iostream>
#include <jni.h>
#include <memory>

#include "include/api/TimeAndSale.h"
#include "include/api/Api.h"
#include "include/api/Subscription.h"

void callMainMethod(JNIEnv* env);

void callback(const TimeAndSale* timeAndSale, int size) {
//  std::cout << "new size = " << size << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cout << timeAndSale[i].toString() << std::endl;
  }
}

int main() {
//    callMainMethod(env);
  void* dxFeed = dxfeed_get_instance();
  auto connection = dxfeed_create_connection(dxFeed, "demo.dxfeed.com:7300");
  auto subscription = dxfeed_create_subscription(connection, 0);
  std::cout << "dx subscription wrapper: " << static_cast<dxfeed::Subscription*>(subscription) << std::endl;
  std::cout << "dx subscription jobject: " << static_cast<dxfeed::Subscription*>(subscription)->getSub() << std::endl;

//  jclass pJclass = env->FindClass("com/dxfeed/api/JniTest");
//  if (pJclass != nullptr) {
//    jmethodID methodId = env->GetStaticMethodID(pJclass, "createSubscription", "()J");
//    jlong dxSub = env->CallStaticLongMethod(pJclass, methodId);
//    std::cout << dxSub;

//    jmethodID addEventListenerMethodId = env->GetStaticMethodID(pJclass, "addEventListener", "(JJ)V");
//    env->CallStaticVoidMethod(pJclass, addEventListenerMethodId, dxSub, callback);
//  } else {
//    std::cout << "Can't find class NativeTest!";
//    return 1;
//  }
  while (true) {}

//  javaVM->DestroyJavaVM();
  return 0;
}

void callMainMethod(JNIEnv* env) {
  jclass pJclass = env->FindClass("com/dxfeed/api/JniTest");
  jmethodID methodId = env->GetStaticMethodID(pJclass, "main", "([Ljava/lang/String;)V");
  if (methodId != nullptr) {
    jstring hello = env->NewStringUTF("ETH/USD:GDAX");
    jclass clazz = env->FindClass("Ljava/lang/String;");
    jobjectArray pArray = env->NewObjectArray(1, clazz, nullptr);
    env->SetObjectArrayElement(pArray, 0, hello);
    env->CallStaticVoidMethod(pJclass, methodId, pArray);
  }
}