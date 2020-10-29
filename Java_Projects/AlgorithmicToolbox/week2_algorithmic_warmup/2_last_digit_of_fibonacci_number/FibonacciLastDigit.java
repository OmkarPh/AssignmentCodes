import java.util.*;

public class FibonacciLastDigit {
    private static long first60[] = new long[62];

    static {
        first60[0] = 0;
        first60[1] = 1;
        for(int i = 2; i<62; i++)
            first60[i] = first60[i-1] + first60[i-2];
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            System.out.println(first60[n % 60] % 10);
    }
}

