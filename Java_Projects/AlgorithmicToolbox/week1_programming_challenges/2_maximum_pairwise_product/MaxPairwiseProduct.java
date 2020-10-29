import java.util.*;
import java.io.*;

public class MaxPairwiseProduct {
    static long getMaxPairwiseProduct(long[] numbers) {
    	if(numbers.length == 0)
    		return 0;
    	if(numbers.length == 1)
    		return numbers[0];
    	if(numbers.length == 2)
    		return numbers[0]*numbers[1];
        int max, max2;
        if(numbers[0] >= numbers[1]) {
        	max = 0;
        	max2 = 1;
        } else {
        		max = 1;
        		max2 = 0;
        	}

        //System.out.println("max: "+numbers[max]+", max2: "+numbers[max2]);
        for (int i = 0; i < numbers.length; i++) 
        	if(numbers[i] > numbers[max])
        		max = i;
        
        for(int i =0; i<numbers.length; i++)
        	if(numbers[i] > numbers[max2] && i != max)
        		max2 = i;

        //System.out.println("max: "+numbers[max]+", max2: "+numbers[max2]);
        return numbers[max]*numbers[max2];
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        long n = scanner.nextInt();
        long[] numbers = new long[(int)n];
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextInt();
        }
        System.out.println(getMaxPairwiseProduct(numbers));
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            try {
                br = new BufferedReader(new
                    InputStreamReader(stream));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        long nextInt() {
        	return Long.parseLong(next());
        }
    }

}
