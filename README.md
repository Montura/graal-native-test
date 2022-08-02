# graal-native-test

## Experiments with system properties based on docs:
* https://www.graalvm.org/22.1/reference-manual/native-image/Properties/

### System properties
* Passing `-D<key>=<value>` as an argument to **_native-image_** affects properties 
seen at **_executable build time_**:
  * `native-image -Dfoo=bar App`
* Passing `-D<key>=<value>` as an argument to a **_native executable_** affects properties
seen at **_executable runtime_**:
  * `./app -Dfoo=bar` 

```
---- begin [Java MAIN] NativeTest:::main(String[] args) ---
	[NATIVE]: JavaVMPtr = 0x1072e36b8, JNIEnv = 0x7f8f97d04080; rawJniEnv = 140254704058496
	[JAVA]: SystemProperties in context: JAVA_MAIN, graalTreadPtr = 140254704058496
		 value of static property: MY_STATIC_VALUE
		 valur of dxfeed.address property: 172.13.14.15
---- end [Java MAIN] NativeTest:::main(String[] args) ---
---- begin [IsolateThread thread] dumpSystemProperties ---
	[JAVA]: SystemProperties in context: @CEntryPoint, thread = 140254972518784
		 value of static property: null
		 value of dxfeed.address property: null
---- end [IsolateThread thread] dumpSystemProperties ---
Property value for key: dxfeed.address is 172.13.14.15

```
