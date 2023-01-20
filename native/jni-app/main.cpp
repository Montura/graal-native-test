#include <iostream>
#include <jni.h>

int main() {
    const char* classpath = "-Djava.class.path=/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/classes";
    JavaVMOption jvmopt[1];
    jvmopt[0].optionString = const_cast<char*>(classpath);

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
    jclass pJclass = env->FindClass("NativeTest");
    if (pJclass != nullptr) {
        jmethodID methodId = env->GetStaticMethodID(pJclass, "main", "([Ljava/lang/String;)V");
        if (methodId != nullptr) {
            jstring hello = env->NewStringUTF("Hello");
            jstring world = env->NewStringUTF("World");
            jclass clazz = env->FindClass("Ljava/lang/String;");
            jobjectArray pArray = env->NewObjectArray(3, clazz, nullptr);
            env->SetObjectArrayElement(pArray, 0, hello);
            env->SetObjectArrayElement(pArray, 1, world);
            env->CallStaticVoidMethod(pJclass, methodId, pArray);
        }
    } else {
        std::cout << "Can't find class NativeTest!";
        return 1;
    }

    javaVM->DestroyJavaVM();
    return 0;
}