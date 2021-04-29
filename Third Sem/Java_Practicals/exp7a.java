import java.util.Scanner;
/**
 * in this class we are adding the square root of indivisual numbers;
 */
public class exp7a{
    /**
     * in this method we are taking the numbers as input and returning the addtion to main function;
     * @param x;
     * @return to main;
     */
    public static int add(int ...x)
    {
        return x[0]*x[0]+x[1]*x[1];
    }
    /**
     * this is the main method where the calling to add function is done and printing the result;
     * @param args
     */
    public static void main(String args[])
    {   //creating Scanner class object and passing system.in ;
        Scanner sc= new Scanner(System.in);
        System.out.println("enter the first number:");
        int n1=sc.nextInt();
        System.out.println("enter the second number:");
        int n2=sc.nextInt();
        int a=exp7a.add(n1,n2);
        System.out.print("the addtion of square root of indivisual is :"+a);
    }
}