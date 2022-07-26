# graal-native-test

There is a problem with annotation @CFunction on Windows platform.

"Exception thrown at 0x00007FFA0F6F0000 (GraalSample.dll) in native.exe: 0xC0000005: Access violation executing location 0x00007FFA0F6F0000."

Steps to reproduce:
1. Download GraalVM CE Build v22.1.0 on Apr 26 (https://github.com/graalvm/graalvm-ce-builds/releases/tag/vm-22.1.0)
2. 
```
export JAVA_HOME=`path_to_graalvm_ce_build_22.1.0`
```
3. 
```
git clone https://github.com/Montura/graal-native-test
cd graal-native-test
```
4. 
* Windows
```
mvn clean package -Pgraal-win 
```
* Linux 
```
mvn clean package -Pgraal-linux
```
* MacOS
```
mvn clean package -Pgraal-mac 
```
5. 
```
cd native
cmake .
make
./native
```
