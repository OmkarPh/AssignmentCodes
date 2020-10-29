import java.util.*;

public class GCD {
  private static int gcd(int a, int b) {
    if(a == 0)
      return b;
    if(b==0)
      return a;
    if(a==b)
      return a;
    return gcd(b, a%b);
  }

  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    int a = scanner.nextInt();
    int b = scanner.nextInt();

    System.out.println(gcd(a, b));
  }
}
