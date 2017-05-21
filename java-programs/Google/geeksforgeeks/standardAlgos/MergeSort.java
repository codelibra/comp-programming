package standardAlgos;

public class MergeSort {
    private static Integer arrayList[] = new Integer[10];
    
    public static void swap(int a, int b) {
        Integer tempInteger = arrayList[a];
        arrayList[a] = arrayList[b];
        arrayList[b] = tempInteger;
    }
    
    public static void merge(int lo, int mid, int hi){
        Integer temp[] = new Integer[10];
        
        int i=lo, j=mid+1, k=lo;
        while(i<=mid && j<=hi){
            if(arrayList[i]<arrayList[j])
            {
                temp[k] = arrayList[i];
                i++;
                k++;
            }
            else{
                temp[k] = arrayList[j];
                j++;
                k++;
            }
        }
        
        while(i<=mid){
            temp[k] = arrayList[i];
            ++i;
            ++k;
        }
        
        while(j<=hi){
            temp[k] = arrayList[j];
            ++j;
            ++k;
        }
        for (int k2 = lo; k2 <= hi; k2++) {
            arrayList[k2] = temp[k2];
        }
        
    }
    
    public static void mergeSort(int lo, int hi) {
        if(lo>=hi) return;
        
        int mid = (lo+hi)/2;
        mergeSort(lo, mid);
        mergeSort(mid +1 , hi);
        merge(lo, mid, hi);
    }
    
    public static void  print() {
        for (int i = 0; i < arrayList.length; i++) {
            System.out.print(arrayList[i]+" ");
        }
        System.out.println();
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
        mergeSort(0,9);
        print();
    }


}
