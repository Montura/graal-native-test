#include <iostream>
#include <jni.h>

#include "classpath.h"

void callMainMethod(JNIEnv* env);

//extern "C" JNIEXPORT
//jlong JNICALL Java_com_dxfeed_api_JniTest_nCreateDxFeedSubscription(JNIEnv*, jclass, jobject dxFeedSub);

int main() {
    JavaVMOption jvmopt[1];
    jvmopt[0].optionString = const_cast<char*>(QD_CLASS_PATH.c_str());

    JavaVMInitArgs vmArgs;
    vmArgs.version = JNI_VERSION_1_8;
    vmArgs.nOptions = 1;
    vmArgs.options = jvmopt;
    vmArgs.ignoreUnrecognized = JNI_TRUE;

  // Create the JVM
    JavaVM *javaVM;
    JNIEnv *env;
    long flag = JNI_CreateJavaVM(&javaVM, (void**)&env, &vmArgs);
    if (flag == JNI_ERR) {
        std::cout << "Error creating VM. Exiting...n";
        return 1;
    }
//    callMainMethod(env);

    jclass pJclass = env->FindClass("com/dxfeed/api/JniTest");
    if (pJclass != nullptr) {
        jmethodID methodId = env->GetStaticMethodID(pJclass, "createSubscription", "()J");
        jlong i = env->CallStaticLongMethod(pJclass, methodId);
        std::cout << i;

    } else {
        std::cout << "Can't find class NativeTest!";
        return 1;
    }

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