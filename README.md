# graal-native-test

See the repository branches for Graal examples.

### Requirements

[GraalVM CE 22.1](https://github.com/graalvm/graalvm-ce-builds/releases/tag/vm-22.1.0)

```
openjdk 11.0.15 2022-04-19
OpenJDK Runtime Environment GraalVM 22.1.1.0-dev (build 11.0.15+10-jvmci-22.1-b06)
OpenJDK 64-Bit Server VM GraalVM 22.1.1.0-dev (build 11.0.15+10-jvmci-22.1-b06, mixed mode, sharing)
```

### How to run

```
$ [set | export] JAVA_HOME=`path_to_graalvm_ce_build_22.1.0`
$ git clone https://github.com/dxFeed/graal-native-test.git
$ cd graal-native-test
```

#### Mac OS
```
$ mvn clean package -P graal-mac
```

* Artifacts:
  * `target/native-image/GraalSample.dylib`
  * `target/native-image/GraalSample.h`
  * `newCapCacheDir/*.cap`

#### Linux
```
$ mvn clean package -P graal-linux
```

* Artifacts:
    * `target/native-image/GraalSample.so`
    * `target/native-image/GraalSample.h`
    * `newCapCacheDir/*.cap`

#### Windows 
```
$ mvn clean package -P graal-win
```

* Artifacts:
    * `target/native-image/GraalSample.dll`
    * `target/native-image/GraalSample.lib`
    * `target/native-image/GraalSample.h`
    * `newCapCacheDir/*.cap`

#### Run native executable
```
~/graal-native-test$ cd native
~/graal-native-test$ mkdir build
~/graal-native-test$ cd build
~/graal-native-test/native$ cmake ../
~/graal-native-test/native$ cmake --build .
~/graal-native-test/native$ cd ../bin
~/graal-native-test/native/bin$ ./native
```

