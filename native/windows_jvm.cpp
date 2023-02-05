#include <Windows.h>
#include <iostream>
#include <jni.h>

typedef jint(JNICALL *CreateJavaVM_t)(JavaVM **pvm, void **env, void *args);
typedef jclass(JNICALL *FindClassFromBootLoader_t)(JNIEnv *env, const char *name);

static HINSTANCE JAVA_DLL;
static HINSTANCE JVM_DLL;

HRESULT loadLibrary(HINSTANCE* hinstance, const wchar_t* libPath) {
    *hinstance = LoadLibraryW(libPath);
    if (!JAVA_DLL) {
        std::cerr << "Can't load lib from: " << libPath << "\n";
        return S_FALSE;
    }
    return S_OK;
}

// https://docs.oracle.com/en/java/javase/12/docs/specs/jni/invocation.html#creating-the-vm
void loadVmOnWindows() {
    CreateJavaVM_t createJavaVM;
    FindClassFromBootLoader_t findBootClass;

    auto javaDllPath = L"D:\\work\\graal-native-test\\native\\cmake-build-debug\\java.dll";
    HRESULT success = loadLibrary(&JAVA_DLL, javaDllPath);
    if (FAILED(success)) return;

    auto jvmDllPath = L"D:\\work\\graal-native-test\\native\\cmake-build-debug\\jvm.dll";
    success = loadLibrary(&JVM_DLL, jvmDllPath);
    if (FAILED(success)) return;

    createJavaVM = (CreateJavaVM_t)GetProcAddress(JVM_DLL, "JNI_CreateJavaVM");
    findBootClass = (FindClassFromBootLoader_t)GetProcAddress(JVM_DLL, "JVM_FindClassFromBootLoader");
    if (createJavaVM == 0 || findBootClass == 0) {
        std::cout << "GetProcAddress failed: " << createJavaVM << ", " << findBootClass << "\n";
        JVM_DLL = 0;
    }

    JNIEnv* jniEnv = nullptr;
    JavaVM* javaVM = nullptr;
    JavaVMInitArgs vmArgs;
//    JNI_GetDefaultJavaVMInitArgs(&vmArgs);

    JavaVMOption options[4];
    options[0].optionString = "-Djdk.module.main=com.dxfeed.api"; /* user classes */
    options[1].optionString = "-Dsun.java.command=JniTest"; /* user classes */
    options[2].optionString = "-Djava.class.path=D:\\work\\graal-native-test\\target\\classes"; /* user classes */
    options[3].optionString = "-verbose:jni";                   /* print JNI-related messages */

    vmArgs.version = JNI_VERSION_1_8;
    vmArgs.options = options;
    vmArgs.nOptions = 4;
    vmArgs.ignoreUnrecognized = JNI_FALSE;
//
//    // Create the JVM
    long flag = JNI_CreateJavaVM(&javaVM, (void**) &jniEnv, &vmArgs);
    if (flag == JNI_ERR) {
        throw std::runtime_error("Error creating VM. Exiting...n");
    }
}