package Unit2;

import java.util.Arrays;
import java.util.Scanner;

public class Anagram {

    static boolean areAnagram(char[] str1, char[] str2)
    {
        // Get lenghts of both strings
        int n1 = str1.length;
        int n2 = str2.length;

        // If length of both strings is not same,
        // then they cannot be anagram
        if (n1 != n2)
            return false;

        // Sort both strings
        Arrays.sort(str1);
        Arrays.sort(str2);

        // Compare sorted strings
        for (int i = 0; i < n1; i++)
            if (str1[i] != str2[i])
                return false;

        return true;
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter first word : ");
        String str1 = scanner.nextLine();
        System.out.println("Enter second word : ");
        String str2 = scanner.nextLine();
        String s1 = str1.replaceAll("\\s", "");
        String s2 = str2.replaceAll("\\s", "");
        char str3[] = s1.toCharArray();
        char str4[] = s2.toCharArray();

        // Function Call
        if (areAnagram(str3, str4))
            System.out.println("The two strings are"
                    + " anagram of each other");
        else
            System.out.println("The two strings are not"
                    + " anagram of each other");
    }
}