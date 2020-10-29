import java.math.BigInteger;
import java.util.Scanner;
public class FibonacciHuge {
    private static BigInteger calc_fib(long n) {

        BigInteger a = new BigInteger(String.valueOf(0));
        BigInteger b = new BigInteger(String.valueOf(1));

        if(n<=1)
            return new BigInteger(String.valueOf(n));

        BigInteger newer = new BigInteger(String.valueOf(0));
        for(int i =0; i<n; i++){
            newer = a.add(b);
            a = b;
            b = newer;
        }
    return newer;
}
    private static long pisanoPeriod(long m){
        long first = 0, second = 1;
        long newer;
        int i = 0;
        for(i=0; i<m*m; i++){
            newer = (first+second)%m;
            first = second;
            second = newer;
            if(first == 0 && second == 1)
                return i+1;
        }
        return i;
    }
    private static String getFibNmodM(long n, long m) {
        if (n <= 1)
            return String.valueOf(n);
        BigInteger fib = calc_fib(n % pisanoPeriod(m));
        System.out.println(fib.toString());
        BigInteger res = fib.mod(BigInteger.valueOf(m));
        System.out.println(res.toString());
        return res.toString();
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long m = scanner.nextLong();
        System.out.println(getFibNmodM(n, m));
    }
}

