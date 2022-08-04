# graal-native-test (Graal interop + JNI + dynamic library)

## Problem

* There is a problem with annotation @CFunction on Windows platform:
   * _"Exception thrown at 0x00007FFA0F6F0000 (GraalSample.dll) in native.exe: 0xC0000005: Access violation executing location 0x00007FFA0F6F0000."_
* I've reported an issue to graal:
   * https://github.com/oracle/graal/issues/4760


### Steps to reproduce:
1. Download GraalVM CE Build v22.1.0 on Apr 26 (https://github.com/graalvm/graalvm-ce-builds/releases/tag/vm-22.1.0)
2. 
```
export JAVA_HOME=`path_to_graalvm_ce_build_22.1.0`
~$ git clone https://github.com/Montura/graal-native-test
~$ cd graal-native-test
~/graal-native-test$ mvn clean package -Pgraal-win|graal-linux|graal-mac
~/graal-native-test$ cd native
~/graal-native-test$ mkdir build
~/graal-native-test$ cd build
~/graal-native-test/native$ cmake ../
~/graal-native-test/native$ cmake --build .
~/graal-native-test/native$ cd ../bin
~/graal-native-test/native/bin$ ./native
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

### Windows issue
* To build native-image on Windows with @CFunction annotation I used native-image option 
   [```-H:NativeLinkerOption="/FORCE:UNRESOLVED"```](pom.xml#L143) to avoid linkage error during the build:

```
Creating library D:\work\graal-tutorial\target\tmp-windows\SVM-1658827308388\GraalSample.lib and object D:\work\graal-tutorial\target\tmp-windows\SVM-1658827308388\GraalSample.exp
GraalSample.obj : error LNK2001: unresolved external symbol testC
D:\work\graal-tutorial\target\native-image\GraalSample.dll : fatal error LNK1120: 1 unresolved externals
        at com.oracle.svm.hosted.image.NativeImageViaCC.handleLinkerFailure(NativeImageViaCC.java:505)
        at com.oracle.svm.hosted.image.NativeImageViaCC.write(NativeImageViaCC.java:452)
        at com.oracle.svm.hosted.image.SharedLibraryImageViaCC.write(SharedLibraryImageViaCC.java:56)
        at com.oracle.svm.hosted.NativeImageGenerator.doRun(NativeImageGenerator.java:695)
        at com.oracle.svm.hosted.NativeImageGenerator.run(NativeImageGenerator.java:515)
        at com.oracle.svm.hosted.NativeImageGeneratorRunner.buildImage(NativeImageGeneratorRunner.java:407)
        at com.oracle.svm.hosted.NativeImageGeneratorRunner.build(NativeImageGeneratorRunner.java:585)
        at com.oracle.svm.hosted.NativeImageGeneratorRunner.main(NativeImageGeneratorRunner.java:128)
        at com.oracle.svm.hosted.NativeImageGeneratorRunner$JDK9Plus.main(NativeImageGeneratorRunner.java:615)
```

#### Possible cause
* I dumped symbols from shared library for **Mac**, **Linux** and **Windows**:
    * **Mac** and **Linux** are export _undefined symbol_ _**testC**_: [mac_symbols](symbols_mac.txt) and [linux_symbols](symbols_linux.txt) 
    * **Windows** can't export _undefined symbol_ _**testC**_ : [windows_symbols](symbols_windows.txt) 
        * I used ["/FORCE:UNRESOLVED"](https://docs.microsoft.com/en-us/cpp/build/reference/force-force-file-output?view=msvc-170) linker option to build shared lib for Windows (so the symbol  _**testC**_ isn't imported)
        * I tried ["/OPT:NOREF"](https://docs.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-6.0/aa278533(v=vs.60)?redirectedfrom=MSDN) and ["/INCLUDE:testC"](https://docs.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-6.0/aa278363(v=vs.60)?redirectedfrom=MSDN), but it doens't help me at all.
    * **GetProcAddress** and **dlsym** proved my assumption: [load_functions](native/load_functions.cpp).
