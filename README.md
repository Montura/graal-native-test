# graal-native-test

There is a problem with annotation @CFunction on Windows platform.

"Exception thrown at 0x00007FFA0F6F0000 (GraalSample.dll) in native.exe: 0xC0000005: Access violation executing location 0x00007FFA0F6F0000."

Steps to reproduce:

1. git clone https://github.com/Montura/graal-native-test
2. cd graal-native-test
3. export JAVA_HOME=path_to_graalvm_ce_build_22.1.0 (3f79371c56c7b91e624de14e3ae096d273f5d020 on Apr 26)
2. mvn clean package -Pgraal-win
3. cd native
4. cmake .
5. make
6. /p
