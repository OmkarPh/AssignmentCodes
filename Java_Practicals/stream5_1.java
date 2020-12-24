import java.util.*;

class stream5_1{

    static int noOfPrimes(Collection<T extends Integer> cs){
        return cs.stream().reduce(0, (c,e) -> c+e);
    }


    public static void main(String[] args) {
        List<Integer> values = Arrays.asList(25,15,23,10,110,300,250);

        int countPrimes = noOfPrimes(values); 
        System.out.println("No of primes: " + countPrimes);

    }
}