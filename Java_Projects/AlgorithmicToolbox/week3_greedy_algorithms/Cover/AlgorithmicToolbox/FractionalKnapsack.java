import java.text.DecimalFormat;
import java.util.Scanner;

public class FractionalKnapsack {

        private static double getOptimalValue(int capacityRemaining, double[] values, double[] weights, double[]rates) {
            double value = 0;
            int maxRateIdx = 0;
            double currWeight;
            while(capacityRemaining > 0){
                // fetch index with highest value in rates
                maxRateIdx = 0;
                for(int i=1; i<values.length; i++)
                    if(rates[i] > rates[maxRateIdx])
                        maxRateIdx = i;
                if(rates[maxRateIdx] == 0)
                    return value;
                currWeight = weights[maxRateIdx];
                if(currWeight > capacityRemaining)
                    currWeight = capacityRemaining;

                value += currWeight*rates[maxRateIdx];
                capacityRemaining -= currWeight;
                rates[maxRateIdx] = 0;
            }

            return value;
        }

        public static void main(String args[]) {
            Scanner scanner = new Scanner(System.in);
            int n = scanner.nextInt();
            int capacity = scanner.nextInt();
            double[] values = new double[n];
            double[] weights = new double[n];
            double[] rates = new double[n];
            for (int i = 0; i < n; i++) {
                values[i] = scanner.nextDouble();
                weights[i] = scanner.nextDouble();
                rates[i] = values[i] / weights[i];
            }
            DecimalFormat numberFormat = new DecimalFormat("#.0000");
            System.out.println(numberFormat.format(getOptimalValue(capacity, values, weights, rates)));
        }


}
