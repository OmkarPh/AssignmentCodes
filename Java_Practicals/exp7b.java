import java.util.Arrays;
/**
 * this is a assignment7 class for sorting the array;
 */
public class exp7b{
   /**
    * This is the main method where the arrays sorted and printed;
    *@param args
    */
   public static void main(String args[])
   {
        System.out.println("sorting the array.....");
        System.out.println("sorted array:");
        Arrays.sort(args);
        for(String i:args)
        {
           System.out.println(i);
        }
   } 
}
