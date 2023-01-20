#include <jni.h>
#include <iostream>


extern "C" {

JNIEXPORT void JNICALL Java_NativeTest_testJNI(JNIEnv* env, jclass cls) {
    std::cout << "Hello from Java_NativeTest_testJNI" << std::endl;
}

}