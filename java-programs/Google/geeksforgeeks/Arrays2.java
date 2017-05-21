/**
 * http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 * @author shiv
 *
 */
public class Arrays2 {

    private static Integer arrayList[] = new Integer[10];
    
    public static void main(String[] args) {
        
        int maxEndingHere = 0;
        int maxSoFar = Integer.MIN_VALUE;
        arrayList[0] = -3;
        arrayList[1] = -1;
        arrayList[2] = -3;
        arrayList[3] = -8;
        arrayList[4] = -9;
        arrayList[5] = -12;
        arrayList[6] = -2;
        arrayList[7] = -23;
        arrayList[8] = -3;
        arrayList[9] = 34;
        for (int i = 0; i < arrayList.length; i++) {
            maxEndingHere = maxEndingHere + arrayList[i];
            if(maxEndingHere>maxSoFar)
                maxSoFar = maxEndingHere;
            if(maxEndingHere<=0)
                maxEndingHere = 0;
        }
        System.out.println(maxSoFar);
    }

}
