import java.util.Locale;

public class NativeTest {
    static String libExt() {
        String osName = System.getProperty("os.name");
        if (osName == null) {
            System.err.println("Unknown OS name");
            return "";
        }
        String osNameTemplate = osName.toLowerCase(Locale.ROOT);
        System.out.println("OS name: " + osNameTemplate);
        if (osNameTemplate.contains("win")) {
            return ".dll";
        } else if (osNameTemplate.contains("mac")) {
            return ".dylib";
        } else {
            return ".so";
        }
    }

    public static void main(String[] args) {
        // comment and you'll see the crash
//        System.load(System.getProperty("user.dir") + "/native/jni-lib/bin/NativeTest" + libExt());
        // Exception in thread "main" java.lang.UnsatisfiedLinkError: 'void NativeTest.testJNI()'
        //	  at NativeTest.testJNI(Native Method)
        //    at NativeTest.main(NativeTest.java:25)

        // "user.dir" property isn't set in C++ app
        System.load("/Users/Andrey.Mikhalev/Documents/work/graal-native-test/native/jni-lib/bin/NativeTest.dylib");

        System.out.println("Hello from Java!");
        testJNI();
        System.out.println("JNI works fine!");
    }

    private static native void testJNI();
}