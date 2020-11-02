package Unit2;

import java.util.Scanner;

public class pairsCount {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the numbers you want in an array");
        int n = scanner.nextInt();
        int numbers [] = new int[n];
        System.out.println("Enter the numbers: ");
        for (int i =0; i<n; i++){
            numbers[i]=scanner.nextInt();
        }

        int sum = 6;
        getPairsCount(numbers, sum);
    }

    public static void getPairsCount(int[] arr, int sum) {

        int count = 0;// Initialize result

        // Consider all possible pairs and check their sums
        for (int i = 0; i < arr.length; i++)
            for (int j = i + 1; j < arr.length; j++)
                if ((arr[i] + arr[j]) == sum)
                    count++;

        System.out.printf("Count of pairs is %d",count);
    }
}
