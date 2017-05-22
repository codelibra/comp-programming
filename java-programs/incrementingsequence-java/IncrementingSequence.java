import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class IncrementingSequence {

    public String canItBeDone(int k, int[] A) {
        Arrays.sort(A);
        for(int i =1; i<=A.length;++i){
            boolean isValid = false;
            
            for (int j = 0; j < A.length; j++) {
                if(A[j]<=i && A[j]%k == i%k){
                    A[j] = 10000;
                    isValid = true;
                    break;
                }
            }
            if(!isValid)
                return "IMPOSSIBLE";
        }
        return "POSSIBLE";
    }

}
