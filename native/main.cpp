#include <iostream>
#include <jni.h>
#include <memory>

#include "classpath.h"
#include "include/api/TimeAndSale.h"

void callMainMethod(JNIEnv* env);

void callback(const TimeAndSale* timeAndSale, int size) {
//  std::cout << "new size = " << size << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cout << timeAndSale[i].toString() << std::endl;
  }
}

int main() {
  std::unique_ptr<JavaVMOption> javaVmOption(new JavaVMOption);
  javaVmOption->optionString = const_cast<char*>(QD_CLASS_PATH.c_str());

  JavaVMInitArgs vmArgs;
  vmArgs.version = JNI_VERSION_1_8;
  vmArgs.nOptions = 1;
  vmArgs.options = javaVmOption.get();
  vmArgs.ignoreUnrecognized = JNI_TRUE;

  // Create the JVM
  JavaVM* javaVM;
  JNIEnv* env;
  long flag = JNI_CreateJavaVM(&javaVM, (void**) &env, &vmArgs);
  if (flag == JNI_ERR) {
    std::cout << "Error creating VM. Exiting...n";
    return 1;
  }

//    callMainMethod(env);

  jclass pJclass = env->FindClass("com/dxfeed/api/JniTest");
  if (pJclass != nullptr) {
    jmethodID methodId = env->GetStaticMethodID(pJclass, "createSubscription", "()J");
    jlong dxSub = env->CallStaticLongMethod(pJclass, methodId);
    std::cout << dxSub;

    jmethodID addEventListenerMethodId = env->GetStaticMethodID(pJclass, "addEventListener", "(JJ)V");
    env->CallStaticVoidMethod(pJclass, addEventListenerMethodId, dxSub, callback);
  } else {
    std::cout << "Can't find class NativeTest!";
    return 1;
  }
  while (true) {}

  javaVM->DestroyJavaVM();
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