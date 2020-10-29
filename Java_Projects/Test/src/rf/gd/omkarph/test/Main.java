package rf.gd.omkarph.test;

public class Main {
        // write your code here
        //  Flour packaging problem on Udemy
        public static boolean canPack(int big, int small, int goal){
            int bigVolPossible = big*5;
            int diff;
            if(bigVolPossible>=goal){
                if(goal%5 == 0)
                    return true;
                while(bigVolPossible>goal ){
                    bigVolPossible -= 5;
                }
            }
            diff = goal-bigVolPossible;
            if(diff<=small)
                return true;
            return false;
        }

        // Largest Prime
            // write your code here
            public static int getLargestPrime(int n){
                if(n<0) return -1;
                int prime=-1;
                boolean flag=false;
                for(int i=(int)n/2; i>1; i--){
                    if(n%i==0){
                        flag = true;
                        prime = i;
                        break;
                    }
                }
                if(!flag)
                    return -1;
                return prime;
            }
        public static void main(String[] args) {
	// write your code here
        if(canPack(1,0,4))
            System.out.println("Yeah");
        else
            System.out.println("Nope");
            System.out.println(getLargestPrime(45));
            System.out.println(getLargestPrime(0));
            System.out.println(getLargestPrime(-1));
    }
}
