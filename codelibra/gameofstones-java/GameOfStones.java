public class GameOfStones {

    public int count(int[] stones) {

        float median = 0;
        int medianInt;
        for (int i = 0; i < stones.length; i++) {
            median = median + stones[i];
        }
        median = median/stones.length;
        medianInt = (int)median;
        
        if(median > medianInt) return -1;
        Integer[] test = new Integer[stones.length];
        
        int ans = 0;
        for (int i = 0; i < stones.length; i++) {
            if(stones[i]>medianInt){
                test[i] = stones[i] - medianInt;
                ans = ans + test[i];
            }
            else if (stones[i]<medianInt) {
                test[i] = medianInt -stones[i];
            }
            else continue;

            if(test[i]>0 && test[i]%2!=0){
                return -1;
            }
        }
        return ans/2;
    }

}
