package standardAlgos;

public class SelectionSort {
    private static Integer arrayList[] = new Integer[10];
    
    private static void swap(int i, int j) {
        int temp = arrayList[j];
        arrayList[j] = arrayList[i];
        arrayList[i]= temp;
    }
    private static void SelectionSort() {
        for (int i = 0; i < arrayList.length; i++) {
            int min = Integer.MAX_VALUE;
            int minIndex = 0;
            for (int j = i; j < arrayList.length; j++) {
                if(arrayList[j]<min){
                    min = arrayList[j];
                    minIndex = j;
                }
            }
            swap(i, minIndex);
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
        SelectionSort();
        for (int i = 0; i < arrayList.length; i++) {
            System.out.print(arrayList[i]+" ");
        }    }
}
