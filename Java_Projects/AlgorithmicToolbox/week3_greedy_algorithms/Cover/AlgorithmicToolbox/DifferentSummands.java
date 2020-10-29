import java.util.*;

public class DifferentSummands {
    private static List<Integer> optimalSummands(int n) {
        List<Integer> summands = new ArrayList<Integer>();
        int sum = 0;
        for(int i=1; sum+i<=n; i++){
            summands.add(i);
            sum += i;
        } 
        if(sum < n){
            int extra = n-sum;
            if(!summands.contains(extra))
                summands.add(extra);
            else{
                summands.set(summands.size()-1, summands.get(summands.size()-1)+extra);
            }
        }
        return summands;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> summands = optimalSummands(n);
        System.out.println(summands.size());
        for (Integer summand : summands) {
            System.out.print(summand + " ");
        }
    }
}

