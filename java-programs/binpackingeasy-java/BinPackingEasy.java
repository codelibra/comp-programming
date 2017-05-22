public class BinPackingEasy {

    public int minBins(int[] item) {
        int[] bins = new int[301];
        int ans = 0, noOfBins = item.length;
        for (int i = 0; i < item.length; i++) {
            bins[item[i]] = bins[item[i]] + 1; 
        }
        while(noOfBins>0){
            int sum = 300, i=300;
            while(i>0 && sum>0){
                if(bins[i]!=0 && (sum-i) >=0){
                    sum = sum -i;
                    bins[i] = bins[i] -1;
                    --noOfBins;
                }
                else{
                    --i;
                }
            }
            ans = ans + 1;
        }
        return ans;
    }

}
