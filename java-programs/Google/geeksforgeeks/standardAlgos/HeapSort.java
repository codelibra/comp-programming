package standardAlgos;


public class HeapSort {

    private static Integer arrayList[] = new Integer[10];
    
    public static void swap(int a, int b) {
        Integer tempInteger = arrayList[a];
        arrayList[a] = arrayList[b];
        arrayList[b] = tempInteger;
    }
    
    public static void maxIndexHeapify(int index, int N){
        
        if(2*index>=N || 2*index+1 >= N){
            return;
        }
        int leftChild = arrayList[2*index];
        int rightChild = arrayList[2*index + 1];
        int maxIndex;
        
        if(leftChild > rightChild ){
            maxIndex = 2*index;
        }
        else{
            maxIndex = 2*index+1;
        }
        if(arrayList[maxIndex] <= arrayList[index])
            return;
        else{
            swap(maxIndex, index);
            maxIndexHeapify(maxIndex, N);
        }
    }
    
    public static void buildHeap() {
        int N = arrayList.length;
        for(int i=(N-2)/2 ; i>=0 ; --i ){
            maxIndexHeapify(i, N);
        }
    }
    
    public static void heapSort() {
        buildHeap();
        print();
        int N = arrayList.length-1;
        while(N>=1){
            swap(N, 0);
            N = N-1;
            maxIndexHeapify(0, N);
            print();
        }
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
        heapSort();
        print();
    }

}
