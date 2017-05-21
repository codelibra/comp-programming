package standardAlgos;

public class Quicksort {
 private static Integer arrayList[] = new Integer[10];
    
    public static void swap(int a, int b) {
        Integer tempInteger = arrayList[a];
        arrayList[a] = arrayList[b];
        arrayList[b] = tempInteger;
    }
    
    
    public static int partition(int lo, int hi) {
        int pivot = arrayList[hi];
        int i = lo-1;
        for (int j = lo; j < hi; j++) {
            if(arrayList[j]<pivot){
                i++;
                swap(i, j);
            }
        }
        swap(i+1, hi);
        return i+1;
    }
    public static void quickSort(int lo, int hi) {
        if(lo>=hi) return;
        int p = partition(lo, hi);
        quickSort(lo, p-1);
        quickSort(p+1, hi);
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
        quickSort(0,9);
        for (int i = 0; i < arrayList.length; i++) {
            System.out.print(arrayList[i]+" ");
        }
    }
}
