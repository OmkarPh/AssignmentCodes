package Unit2;

import java.util.Scanner;

public class Heron {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter The Number : ");
        int a = scanner.nextInt();
        System.out.println((double)Math.round(heron(a) * 10000d) / 10000d);

    }

    public static int ClosetNumber(int a)
    {
        int i;
        a = a - 1;
        while (a != 0)
        {
            for (i = 1; i * i <= a; i++)
            {
                if (i * i == a) {
                    return a;
                }
            }
            a = a - 1;
        }
        return 0;
    }

    public static double heron(int x)
    {
        double a, i;
        a = ClosetNumber(x);
        for (i = 0; i < 4; i++)
        {
            a = 0.5 * (a + x / a);
        }
        return a;
    }
}
