# graal-native-test

There is a problem with annotation @CFunction on Windows platform.

_"Exception thrown at 0x00007FFA0F6F0000 (GraalSample.dll) in native.exe: 0xC0000005: Access violation executing location 0x00007FFA0F6F0000."_

### Steps to reproduce:
1. Download GraalVM CE Build v22.1.0 on Apr 26 (https://github.com/graalvm/graalvm-ce-builds/releases/tag/vm-22.1.0)
2. 
```
export JAVA_HOME=`path_to_graalvm_ce_build_22.1.0`
~$ git clone https://github.com/Montura/graal-native-test
~$ cd graal-native-test
~/graal-native-test$ mvn clean package -Pgraal-win|graal-linux|graal-mac
~/graal-native-test$ cd native
~/graal-native-test/native$ cmake .
~/graal-native-test/native$ make
~/graal-native-test/native$ ./native
```

### Expected output (digits are not valuable):
```
OS name: windows 10
JNI time = 20
C time = 6
dummy time = 6
native time = 1
```

### Actual output:
```
OS name: windows 10
JNI time = 20
```
_"Exception thrown at 0x00007FFA0F6F0000 (GraalSample.dll) in native.exe: 0xC0000005: Access violation executing location 0x00007FFA0F6F0000."_
