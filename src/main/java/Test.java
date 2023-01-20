import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        for (int i = 0; i < args.length; ++i) {
            System.out.println("args[" + i + "] = " + args[i]);
        }
        int[] a = { 3, 2, 95, 4, -3 };
        System.out.println(Arrays.toString(a));
    }
}
