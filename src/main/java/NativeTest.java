import org.graalvm.nativeimage.UnmanagedMemory;
import org.graalvm.nativeimage.c.CContext;
import org.graalvm.nativeimage.c.function.CEntryPoint;
import org.graalvm.nativeimage.IsolateThread;
import com.oracle.svm.core.c.ProjectHeaderFile;
import org.graalvm.word.PointerBase;

import java.util.Collections;
import java.util.List;
import java.util.Locale;

@CContext(NativeTest.CApiDirectives.class)
public class NativeTest {

    static class CApiDirectives implements CContext.Directives {
        @Override
        public List<String> getHeaderFiles() {
            /*
             * The header file with the C declarations that are imported. We use a helper class that
             * locates the file in our project structure.
             */
            return Collections.singletonList(ProjectHeaderFile.resolve("", "c_api.h"));
        }
    }

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

    public static void main(String[] args) {}

    private static byte[] allocJava(int size) {
        return new byte[size];
    }

    private static int getJavaSize(byte[] array) {
        array[array.length / 2] = 1;
        return array.length;
    }

    private static PointerBase allocNative(int size) {
        return UnmanagedMemory.calloc(size);
    }

    private static void dealloc(PointerBase ptr) {
        UnmanagedMemory.free(ptr);
    }


    private static void logMsg(String allocatorName, double time1, double time2, long totalSize, int chunkSize) {
        final double nanosToMillis = 1e6;
        System.out.println("alloc " + allocatorName + " time = " + (time2 - time1) / nanosToMillis + " ms, allocated "
                + totalSize + " bytes by " + chunkSize + " byte chunks");
    }

    private static void testAlloc(int chunkSize) {
        final int n = 10000000;

        long totalSize = 0;
        double time1 = System.nanoTime();
        for (int i = 0; i < n; i++) {
            totalSize += getJavaSize(allocJava(chunkSize));
        }
        double time2 = System.nanoTime();
        logMsg("Java", time1, time2, totalSize, chunkSize);

        totalSize = 0;
        time1 = System.nanoTime();
        for (int i = 0; i < n; i++) {
            PointerBase ptr = allocNative(chunkSize);
            totalSize += chunkSize;
            dealloc(ptr);
        }
        time2 = System.nanoTime();
        logMsg("Native", time1, time2, totalSize, chunkSize);
    }

    @CEntryPoint(name = "test")
    public static void test(IsolateThread thread) {
        System.load(System.getProperty("user.dir") + "/NativeTest" + libExt());

        testAlloc(1);
        testAlloc(2);
        testAlloc(4);
        testAlloc(8);
        testAlloc(16);
    }
}