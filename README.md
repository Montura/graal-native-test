# graal-native-test (IOS example)

### Requirements
* Works only for **_Mac OS_**:
  * **_x86-64_**
  * **_aarch64_**


* Builds **_STATIC_** library for **iOS**:
  * the minimal iOS version is 11
  * iOS device CPU at least since ARMv8 (64-bit, `aarch64`)


* Has two _additional dependencies_ for `aarch64` in `native/graal/ios-libs/`:
  * **_static lib_** `graal-svm-arm64-ios-r.a`
    * built from [dxfeed/labs-openjdk11#release-jmvci-22.1](https://github.com/dxFeed/labs-openjdk-11/tree/release/jvmci/22.1)
  * **_static lib_** `jdk-arm64-ios-r.a`
    * built from [dxfeed/graal#release-graal-vm-22.1](https://github.com/dxFeed/graal/tree/release/graal-vm/22.1)
  * How to build these deps: 
    * **_TODO_**

### How to run on MacOS

```
$ [set | export] JAVA_HOME=`path_to_graalvm_ce_build_22.1.0`
$ git clone https://github.com/dxFeed/graal-native-test.git
$ cd graal-native-test
```

#### Mac OS x86-64
```
$ mvn clean package -Pgraal-ios,gen-cap-cache
```
* You will get en errors report about compilation failure for:
  * `tmparm64-ios/SVM-.../AMD64LibCHelperDirectives.c`
  * `tmparm64-ios/SVM-.../PosixDirectives.c`



#### Mac OS x86-64 with llvm backend
* Artifacts:
    * `target/native-image/GraalSample.o`
    * `target/native-image/llvm.o`

#### Mac OS x86-64 and aarch64 with defualt graal backend
* Artifacts:
  * `target/native-image/GraalSample.o`