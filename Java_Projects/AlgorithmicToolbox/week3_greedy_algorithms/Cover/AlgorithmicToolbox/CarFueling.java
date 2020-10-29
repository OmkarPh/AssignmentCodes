import java.util.*;
import java.io.*;

public class CarFueling {
    static int computeMinRefills(int dist, int tank, int[] stops) {
        int distCovered = 0;
        int lastDistCovered;
        int refils = 0;
        int stopIdx = 0;
        while(distCovered<=dist){
            lastDistCovered = distCovered;
            while(stopIdx+1<stops.length && stops[stopIdx+1] <= distCovered+tank)
                stopIdx++;
            if(stopIdx == stops.length-1)
                return refils;
            distCovered = stops[stopIdx];
            if(distCovered == lastDistCovered)
                return -1;
            refils++;
        }
        return refils-1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int dist = scanner.nextInt();
        int tank = scanner.nextInt();
        int n = scanner.nextInt();
        int stops[] = new int[n+1];
        for (int i = 0; i < n; i++) {
            stops[i] = scanner.nextInt();
        }
        stops[n] = dist;
        System.out.println(computeMinRefills(dist, tank, stops));
    }
}
