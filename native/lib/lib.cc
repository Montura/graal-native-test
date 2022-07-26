#include <jni.h>

extern "C" {

jint Java_NativeTest_testJNI(JNIEnv* env, jclass cls) {
    return 42;
}

int testC() {
    return 17;
}
}