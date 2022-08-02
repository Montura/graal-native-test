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
        System.load(System.getProperty("user.dir") + "/native/bin/NativeTest" + libExt());

        System.out.println("Hello from Java!");
        testJNI();
        System.out.println("JNI works fine!");
    }

    private static native void testJNI();
}