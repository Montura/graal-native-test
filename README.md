# graal-native-test

## CInterface tutorial based on
* https://github.com/oracle/graal/blob/master/substratevm/src/com.oracle.svm.tutorial/src/com/oracle/svm/tutorial/CInterfaceTutorial.java
* https://github.com/oracle/graal/blob/master/substratevm/src/com.oracle.svm.tutorial/native/cinterfacetutorial.c


### If there is no `CInterfaceTutorial_CInterfaceTutorialDirectives.cap`
1. Add file `native/graal/c_interface.h`:
   * and add the **C declarations** that you want to **_SHARE_** with **Java** using _SVM annotations_:
     * _@CStruct_
     * _@CEnum_
     * _@CField_
     * _@CConstant_
     * etc.
2. Add `CLibraryPath` that point to dir with `c_interface.h` to MVN profile `gen-cap-caphe`:
   *   ```
       <id>gen-cap-cache</id>
       <properties>
           <c.library.path>${project.basedir}/native/graal/</c.library.path>
           <graavm.capcache>
               -H:-UseCAPCache
               -H:+NewCAPCache
               -H:-CheckToolchain
               -H:CAPCacheDir=${project.basedir}/newCapCacheDir
               -H:CLibraryPath=${c.library.path}
           </graavm.capcache>
       </properties>
       ```
   * MVN task will produce a **_NEW cross-platform_** cap-caches for `c_interface.h` to `newCapCacheDir/CInterfaceTutorial_CInterfaceTutorialDirectives.cap`
3. Copy `CInterfaceTutorial_CInterfaceTutorialDirectives.cap` to the **_ALL_** directories with cap-caches:
   * `capcache-linux`
   * `capcache-ios`
   * `capcache-mac`
   * `capcache-mac-arm64`
   * `capcache-win`


### If there is `CInterfaceTutorial_CInterfaceTutorialDirectives.cap`
4. Run MVN task (if ca)
```
mvn clean package -Pgraal-mac|win|linux
```
5. Run native executable
```
~/graal-native-test$ cd native
~/graal-native-test$ mkdir build
~/graal-native-test$ cd build
~/graal-native-test/native$ cmake ../
~/graal-native-test/native$ cmake --build .
~/graal-native-test/native$ cd ../bin
~/graal-native-test/native/bin$ ./native
```

