#include <jni.h>
#include <string>

#include "api/utils/LoadLibrary.h"

namespace dxfeed {
  JNIEnv* jniEnv = nullptr;
  JavaVM* javaVM = nullptr;

  namespace internal {
    void loadJavaVM(const char* javaHome) {
      internal::loadJVMLibrary(javaHome);

      JavaVMOption options[1];
      options[0].optionString =
        "-Djava.class.path=/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/graal-tutorial-1.1-SNAPSHOT.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/auther-api-442.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/dxfeed-api-3.313.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/dxlib-3.313.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/qds-3.313.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/qds-file-3.313.jar:" \
          "/Users/Andrey.Mikhalev/Documents/work/graal-native-test/target/libs/qds-tools-3.313.jar";


      JavaVMInitArgs vmArgs;
      vmArgs.version = JNI_VERSION_1_8;
      vmArgs.options = options;
      vmArgs.nOptions = 1;
      vmArgs.ignoreUnrecognized = JNI_FALSE;

      // Create the JVM
      jint flag = internal::createJavaVM(&javaVM, (void**) &jniEnv, &vmArgs);
      if (flag == JNI_ERR) {
        throw std::runtime_error("Error creating VM. Exiting...n");
      }
    }

    // todo: add dispose!!!!!!!!!!!!!
    void disposeJavaVM() {
      javaVM->DestroyJavaVM();
    }
  }
}