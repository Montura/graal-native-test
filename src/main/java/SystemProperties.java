import org.graalvm.nativeimage.IsolateThread;
import org.graalvm.nativeimage.c.function.CEntryPoint;

public class SystemProperties {
    private static final String STATIC_PROPERTY_KEY = "static_key";
    private static final String DX_FEED_ADDRESS_PROPERTY_KEY = "dxfeed.address";

    public static final String STATIC_PROPERTY;

    static {
        STATIC_PROPERTY = System.getProperty(STATIC_PROPERTY_KEY);
        System.out.println("\t[JAVA]: SystemProperties in context: STATIC_FIELD_INITIALIZER");
        System.out.println("\t\t value of static property: " + STATIC_PROPERTY);
    }

    public String dxFeedAddress;

    public SystemProperties(String context, long graalThreadPtr) {
        System.out.println("\t[JAVA]: SystemProperties in context: " + context + ", graalTreadPtr = " + graalThreadPtr);
        dxFeedAddress = System.getProperty(DX_FEED_ADDRESS_PROPERTY_KEY);
        System.out.println("\t\t value of static property: " + STATIC_PROPERTY);
        System.out.println("\t\t valur of dxfeed.address property: " + dxFeedAddress);
    }

    @CEntryPoint(name="dumpSystemProperties")
    public static void dumpSystemProperties(IsolateThread thread) {
        System.out.println("---- begin [IsolateThread thread] dumpSystemProperties ---");
        long threadPtr = thread.rawValue();
        System.out.println("\t[JAVA]: SystemProperties in context: @CEntryPoint" + ", thread = " + threadPtr);
        System.out.println("\t\t value of static property: " + System.getProperty(STATIC_PROPERTY_KEY));
        System.out.println("\t\t value of dxfeed.address property: " + System.getProperty(DX_FEED_ADDRESS_PROPERTY_KEY));
        System.out.println("---- end [IsolateThread thread] dumpSystemProperties ---");
    }
}
