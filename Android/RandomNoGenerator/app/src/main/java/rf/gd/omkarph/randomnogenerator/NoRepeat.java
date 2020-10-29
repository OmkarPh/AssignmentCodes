package rf.gd.omkarph.randomnogenerator;


public class NoRepeat {
    private boolean[] nos;

    private int low, high;
    private int generated;

    public NoRepeat(int lowerLimit, int upperLimit){
        reset(lowerLimit,upperLimit);
    }
    public void reset(int lowerLimit, int upperLimit){
        low = lowerLimit;
        high = upperLimit;
        nos = new boolean[high-low+1];
        generated = 0;
    }

    public int getLow() {
        return low;
    }
    public int getHigh() {
        return high;
    }
    public boolean isFull(){ return generated >= (high-low+1); }

    public int nextRandom(){
        // See if generated nos have reached capacity
        if(generated >= high-low+1){
            nos = new boolean[high-low+1];
            generated = 0;
        }

        int resultNo = (int) (Math.random() * (high - low + 1) + low);

        while(nos[resultNo-low])
            resultNo = (int) (Math.random() * (high - low + 1) + low);

        nos[resultNo-low] = true;

        generated++;
        return resultNo;
    }

}
