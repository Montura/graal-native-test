import org.graalvm.nativeimage.CurrentIsolate;
import org.graalvm.nativeimage.IsolateThread;
import org.graalvm.nativeimage.c.function.CEntryPoint;

public class NativeTestMain {

    @CEntryPoint(name = "NativeTestMain_createIsolate", builtin = CEntryPoint.Builtin.CREATE_ISOLATE)
    static native IsolateThread createIsolate();

    public static void main(String[] args) {
        System.out.println("---- begin [Java MAIN] NativeTest:::main(String[] args) ---");
        nInitJNI();

        long graalThreadPtr = CurrentIsolate.getCurrentThread().rawValue();
        SystemProperties rp = new SystemProperties("JAVA_MAIN", graalThreadPtr);

        System.out.println("---- end [Java MAIN] NativeTest:::main(String[] args) ---");
    }

    private static native void nInitJNI();
}
