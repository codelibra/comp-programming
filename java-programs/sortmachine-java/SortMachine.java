import java.util.Arrays;

public class SortMachine {

    public int countMoves(int[] a) {
        int b[] = new int[a.length];
        for (int i = 0; i < b.length; i++) {
            b[i] = a[i];
        }
        Arrays.sort(a);
        int p=-1;
        for (int i = 0; i < b.length; i++) {
            if(a[p+1]==b[i]){
                p++;
            }
        }
        return a.length - p -1;
    }

}
