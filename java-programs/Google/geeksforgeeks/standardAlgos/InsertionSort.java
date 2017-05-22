package standardAlgos;

public class InsertionSort {

    private static Integer arrayList[] = new Integer[10];
    
    public static void swap(int a, int b) {
        Integer tempInteger = arrayList[a];
        arrayList[a] = arrayList[b];
        arrayList[b] = tempInteger;
    }
    public static void insertionSort() {
        int i =0, j=0;
        
        for (i=0;i<arrayList.length-1;++i){
            for(j=i;j> 0 ; --j){
                if(arrayList[j]<arrayList[j-1])
                {
                    swap(j, j-1);
                }
            }
        }
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
        insertionSort();
        for (int i = 0; i < arrayList.length; i++) {
            System.out.print(arrayList[i]+" ");
        }
    }

}
