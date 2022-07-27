#include <cassert>
#include <cstring>

#include "graal/c_api.h"
#include "jni.h"
#include "system_properties.h"

struct DxJniContext {
    JNIEnv* main_env; // thread
    JavaVM* main_javaVM; // process

    jclass systemClazz;
    jmethodID systemClazzMethodGetProperty;
} dxJniContext;

template < typename ReturnType, typename ArgType >
constexpr inline ReturnType cast(ArgType arg) {
    return reinterpret_cast<ReturnType>(arg);
}

void testProps(JNIEnv* env, const char* propertyKey, const char* propertyValue) {
    jstring propertyNameString = env->NewStringUTF(propertyKey);
    auto propertyString = cast <jstring>(
        env->CallStaticObjectMethod(dxJniContext.systemClazz,
                                                      dxJniContext.systemClazzMethodGetProperty,
                                                      propertyNameString));
    if (propertyString != nullptr) {
        const char* property = env->GetStringUTFChars(propertyString, 0);
        bool isSame = !strcmp(property, propertyValue);
        if (!isSame) {
            fprintf(stderr, "Wrong property value for key: %s, expected: %s, actual: %s\n", propertyKey, propertyValue,
                    property);
        } else {
            fprintf(stdout, "Property value for key: %s is %s\n", propertyKey, propertyValue);
        }
        env->ReleaseStringUTFChars(propertyString, property);
    }
}

extern "C" {
    JNIEXPORT
    void JNICALL Java_NativeTestMain_nInitJNI(JNIEnv_* env, jclass*) {
        dxJniContext.main_env = env;
        jint hr = env->GetJavaVM(&dxJniContext.main_javaVM);
        if (hr == 0) {
            dxJniContext.systemClazz = cast<jclass>(env->NewGlobalRef(env->FindClass("java/lang/System")));
            dxJniContext.systemClazzMethodGetProperty = env->GetStaticMethodID(dxJniContext.systemClazz, "getProperty",
                                                                               "(Ljava/lang/String;)Ljava/lang/String;");

            fprintf(stdout, "\t[NATIVE]: JavaVMPtr = %p, JNIEnv = %p; rawJniEnv = %lld\n",
                    dxJniContext.main_javaVM, dxJniContext.main_env, dxJniContext.main_env);
        } else {
            fprintf(stderr, "\t Can't receive vmPtr!");
        }
    }
}

void testSystemProperties(int argc, char** argv, graal_isolatethread_t* thread) {
    // call NativeTestMain::main(String[] args)          [JAVA main thread]
    run_main(argc, argv);
    //  ->  NativeTestMain::main(String[] args) calls:   [JAVA main thread]
    //      a) Java_NativeTestMain_nInitJNI();           [JAVA main thread]

    // 2. call @CEntryPoint(dumpSystemProperties)        [graal isolate thread]
    dumpSystemProperties(thread);

    // 3. test SystemProperties from thread A using JNI and reflection [native thread]
    JNIEnv* localEnv = nullptr;
    jint hr = dxJniContext.main_javaVM->GetEnv((void**)&localEnv, JNI_VERSION_10);
    if (hr == 0) {
        assert(localEnv == dxJniContext.main_env);
        testProps(localEnv, STATIC_PROPERTY_KEY, STATIC_PROPERTY_VALUE);
        testProps(localEnv, DXFEED_ADDRESS_PROPERTY_KEY, DXFEED_ADDRESS_PROPERTY_VALUE);
    }
}