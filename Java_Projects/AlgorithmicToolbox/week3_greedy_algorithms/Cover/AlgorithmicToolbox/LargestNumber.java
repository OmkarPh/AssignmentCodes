
import java.util.*;

public class LargestNumber {
    static int last;
    private static int getFirstDigit(int n){
        last = n;
        while(n!=0){
            last = n;
            n /= 10;
        }
        return last;
    }
    private static String largestNumber(ArrayList<String> nums) {
        String result = "";
        int max = 0;
        String temp = "";
        for(int i=0; i+1<nums.size(); i++){
            if(getFirstDigit(Integer.parseInt(nums.get(i))) == getFirstDigit(Integer.parseInt(nums.get(i+1)))){
                temp = nums.get(i);
                nums.set(i,nums.get(i+1));
                nums.set(i+1,temp);
            }
        }
        for(int i=nums.size()-1; i>-1; i--)
            result += nums.get(i);

        return result;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<String> numbers = new ArrayList<String>();
        for (int i = 0; i < n; i++)
            numbers.add(scanner.next());
        Collections.sort(numbers);
        System.out.println(largestNumber(numbers));
    }


}
