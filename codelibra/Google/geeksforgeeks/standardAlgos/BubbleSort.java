package standardAlgos;


public class BubbleSort {

    private static Integer arrayList[] = new Integer[10];
    
    public static void swap(int a, int b) {
        Integer tempInteger = arrayList[a];
        arrayList[a] = arrayList[b];
        arrayList[b] = tempInteger;
    }
    public static void bubbleSort() {
        int i =0, j=0;
        
        boolean swapped = false;
        for (i=0;i<arrayList.length-1;++i){
            for(j=0;j<arrayList.length-i-1 ; ++j){
                if(arrayList[j]>arrayList[j+1])
                {
                    swap(j, j+1);
                    swapped = true;
                }
            }
            if(!swapped)
                break;
            else swapped=!swapped;
      
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
        bubbleSort();
        for (int i = 0; i < arrayList.length; i++) {
            System.out.print(arrayList[i]+" ");
        }
    }
}
