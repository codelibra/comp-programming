/**
 * http://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
 * 
 * @author shiv
 *
 */
public class Arrays4 {
    private static Integer arrayList[] = new Integer[10];
    
    public static void swap(int a , int b) {
        int temp = arrayList[a];
        arrayList[a] = arrayList[b];
        arrayList[b] = temp;
    }
    public static void sort() {
        int lo=0, hi = arrayList.length -1 , mid = 0;
        for (mid = 0; mid < hi; ) {
            if(arrayList[mid]==0){
                swap(lo, mid);
                lo++;
                continue;
            }
            else if (arrayList[mid]==2) {
                swap(mid, hi);
                hi--;
                continue;
            }
            else{
                mid++;
            }
            print();
            System.out.println();
        }
    }
    
    public static void print() {
        for (int i = 0; i < arrayList.length; i++) {
            System.out.print(arrayList[i]+" ");
        }
    }
    
    public static void main(String[] args) {
        arrayList[0] = 1;
        arrayList[1] = 0;
        arrayList[2] = 0;
        arrayList[3] = 2;
        arrayList[4] = 1;
        arrayList[5] = 2;
        arrayList[6] = 2;
        arrayList[7] = 1;
        arrayList[8] = 0;
        arrayList[9] = 0;
        sort();
        print();
    }
}
