package Unit2;

import java.util.Scanner;

public class add {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter first digit:");
        int a = scanner.nextInt();
        System.out.println("Enter second digit:");
        int b = scanner.nextInt();
        int c = a+b;
        System.out.println("Addition of two digits : " + c);
    }
}
