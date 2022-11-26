package Unit2;

import java.util.Scanner;

public class string {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter string:");
        String s = scanner.nextLine();
        int number = Integer.parseInt(s);
        System.out.println("After parsing the string into Int: " + number);
    }
}
