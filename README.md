# graal-native-test (JNI example)

### How to run

```
$ [set | export] JAVA_HOME=`path_to_graalvm_ce_build_22.1.0`
$ git clone https://github.com/dxFeed/graal-native-test.git
$ cd graal-native-test
```

#### Run native executable
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
    System.load(System.getProperty("user.dir") + "/native/bin/NativeTest" + libExt());

    System.out.println("Hello from Java!");
    testJNI();
    System.out.println("JNI works fine!");
}
```
