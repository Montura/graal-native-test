# graal-native-test (JNI example)

### How to run

```
$ [set | export] JAVA_HOME=`path_to_graalvm_ce_build_22.1.0`
$ git clone https://github.com/dxFeed/graal-native-test.git
$ cd graal-native-test
```

#### Create shared lib with JNI implementation
```c++
extern "C" JNIEXPORT void JNICALL Java_NativeTest_testJNI(JNIEnv* env, jclass cls) {
    std::cout << "Hello from Java_NativeTest_testJNI" << std::endl;
}

```

```
~/graal-native-test$ cd native
~/graal-native-test$ mkdir build
~/graal-native-test$ cd build
~/graal-native-test/native$ cmake ../
~/graal-native-test/native$ cmake --build .
```

* Artifacts:
  * `native/bin/NativeTest.*`

#### Run java main
```java
public static void main(String[] args) {
    // comment and you'll see the crash
    System.load(System.getProperty("user.dir") + "/native/bin/NativeTest" + libExt()); 
    // Exception in thread "main" java.lang.UnsatisfiedLinkError: 'void NativeTest.testJNI()'
    //   at NativeTest.testJNI(Native Method)
    //   at NativeTest.main(NativeTest.java:25)

    System.out.println("Hello from Java!");
    testJNI();
    System.out.println("JNI works fine!");
}
```


#### Output 
```
OS name: mac os x
Hello from Java!
Hello from Java_NativeTest_testJNI
JNI works fine!
```
