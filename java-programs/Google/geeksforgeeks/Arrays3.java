/**
 * http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
 * @author shiv
 *
 */
public class Arrays3 {
    private static Integer arrayList[] = new Integer[10];
    
    public static int findPivot(int lo, int hi) {
        
        if(lo<=hi){
            int mid = lo+(hi-lo)/2;

            if(hi == lo)
                return lo;
            if(mid> lo && arrayList[mid-1]>arrayList[mid])
                return mid -1;
            else if (mid+1<hi && arrayList[mid]>arrayList[mid+1]) 
                return mid;
            
            if(arrayList[hi]<=arrayList[mid])
                lo = mid +1;
            else
                hi = mid -1;
        }
        return -1;
    }
    
    public static void main(String[] args) {
        arrayList[0] = 1;
        arrayList[1] = 2;
        arrayList[2] = 3;
        arrayList[3] = 6;
        arrayList[4] = 8;
        arrayList[5] = 9;
        arrayList[6] = 12;
        arrayList[7] = 23;
        arrayList[8] = 30;
        arrayList[9] = 34;
        findPivot(0, 10);
    }

}
