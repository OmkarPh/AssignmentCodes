package Unit2;

import org.w3c.dom.ls.LSOutput;

import java.util.Scanner;

public class int_squares {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a,b,c,d,e;
        System.out.println("Enter first digit:");
        a=sc.nextInt();
        b = a*a;
        System.out.println("Enter second digit:");
        c = sc.nextInt();
        d = c*c;
        e = b+d;
        System.out.println("Sum of squares of two integers is : " + e);
    }

}
