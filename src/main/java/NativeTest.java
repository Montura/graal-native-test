// ./javac NativeTest.java
// ./native-image java.com.com.dxfeed.NativeTest --shared

import org.graalvm.nativeimage.c.function.CFunction;
import org.graalvm.nativeimage.c.function.CEntryPoint;
import org.graalvm.nativeimage.IsolateThread;

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

    }
    public native static int testJNI();

    @CFunction
    public native static int testC();

    static interface DummyInterface {
        int test();
    }
    static class DummyClass implements DummyInterface {
        public int test() {
            return testC();
        }
    }
    static DummyInterface dummy = new DummyClass();

    @CEntryPoint(name = "test")
    public static void test(IsolateThread thread) {

        System.load(System.getProperty("user.dir") + "/NativeTest" + libExt());

        int n = 10000000;

        for (int i = 0; i < n; i++) {
            testJNI();
        }
        long time1 = System.nanoTime();
        for (int i = 0; i < n; i++) {
            testJNI();
        }
        long time2 = System.nanoTime();
        System.out.println("JNI time = " + (time2 - time1) / n);

        for (int i = 0; i < n; i++) {
            testC();
        }
        long time3 = System.nanoTime();
        for (int i = 0; i < n; i++) {
            testC();
        }
        long time4 = System.nanoTime();
        System.out.println("C time = " + (time4 - time3) / n);

        for (int i = 0; i < n; i++) {
            dummy.test();
        }
        long time5 = System.nanoTime();
        for (int i = 0; i < n; i++) {
            dummy.test();
        }
        long time6 = System.nanoTime();
        System.out.println("dummy time = " + (time6 - time5) / n);
    }
}