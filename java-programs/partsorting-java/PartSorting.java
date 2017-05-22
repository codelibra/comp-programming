public class PartSorting {

    private static int[] swap(int []arr, int i, int j) {
        for (int j2 = j; j2 >i; j2--) {
            int t = arr[j2];
            arr[j2] = arr[j2-1];
            arr[j2-1] = t;
        }
        return arr;
    }
    

    public int[] process(int[] data, int nSwaps) {
        
        for (int i = 0; i < data.length; i++) {
            if(nSwaps<=0)break;
            int max = data[i], index=i;
            for (int k = i; k <= i+nSwaps && k<data.length; k++) {
                if(max<data[k]){
                    max = data[k];
                    index = k;
                }
            }
            if(index!=i){
                nSwaps = nSwaps - (index-i);
                data = swap(data, i,index);
            }
        }
        return data;
    }

}
