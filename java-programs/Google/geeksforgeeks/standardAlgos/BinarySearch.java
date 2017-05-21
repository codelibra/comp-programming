package standardAlgos;

public class BinarySearch {
private static Integer arrayList[] = new Integer[10];
    
    public static int binarySearch(int val) {
        int lo =0, hi = arrayList.length;
        while(lo<=hi){
            int mid = lo +(hi-lo)/2;
            if(arrayList[mid]==val){
                return val;
            }
            else if(arrayList[mid]>val){
                hi = mid -1;
            }
            else{
                lo = mid +1;
            }
        }
        return -1;
    }
    
    public static void main(String[] args) {
        arrayList[0] = 3;
        arrayList[1] = 1;
        arrayList[2] = 6;
        arrayList[3] = 8;
        arrayList[4] = 9;
        arrayList[5] = 12;
        arrayList[6] = 2;
        arrayList[7] = 23;
        arrayList[8] = 3;
        arrayList[9] = 34;
        System.out.println(binarySearch(6));
        System.out.println(binarySearch(-9));
    }
}
