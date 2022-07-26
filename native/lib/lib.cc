#include <jni.h>

extern "C" {

JNIEXPORT jint JNICALL Java_NativeTest_testJNI(JNIEnv* env, jclass cls) {
    return 42;
}

int testC() {
    return 17;
}
}