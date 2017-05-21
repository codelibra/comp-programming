import java.util.ArrayList;
import java.util.Collections;

/**
 * http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
 * @author shiv
 *
 */

public class Arrays1 {
    private static ArrayList<Integer> arrIntegers = new ArrayList<Integer>();
    
    
    public static void traverse(int sum) {
        int i =0, j=arrIntegers.size()-1;
        while(i<arrIntegers.size() && j>=0){
            if(arrIntegers.get(i) + arrIntegers.get(j) == sum){
                System.out.println(arrIntegers.get(i) +" "+ arrIntegers.get(j) );
                return;
            }
            else if (arrIntegers.get(i) + arrIntegers.get(j) > sum){
                j = j-1;
            }
            else {
                i = i+1;
            }
        }
    }
    
    public static void sort() {
        Collections.sort(arrIntegers);
    }
    public static void main(String[] args) {
        arrIntegers.add(1);
        arrIntegers.add(6);
        arrIntegers.add(2);
        arrIntegers.add(9);
        arrIntegers.add(10);
        sort();
        System.out.println(arrIntegers.toString());
        traverse(10);
    }
}
