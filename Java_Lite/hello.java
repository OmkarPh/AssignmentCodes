/**
 * hello
 */
import java.util.*;
public class hello {

    static void func(int n){
        if(n==1)
            return;
        for(int lv=1; lv<=n; lv++){
            System.out.println("*");
            int inner_lv=1;
            while(inner_lv <= n){
                System.out.println("#");
                continue;
            }
        }
    }

    public static void main(String[] args) {
        String s;
        System.out.println("Enter your name: ");
        Scanner sc = new Scanner(System.in);
        s = sc.nextLine();
        System.out.print("HI "+ s);

        func(5);
    }
    
}