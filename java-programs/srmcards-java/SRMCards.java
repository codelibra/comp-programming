import java.util.Arrays;

public class SRMCards {

	public int maxTurns(int[] cards) {
	    int ans =0, j;
	    Arrays.sort(cards);
	    for (int i = 0; i < cards.length; i++) {
	        for (j = i+1; j < cards.length; j++) {
                if(cards[j]!=cards[j-1]+1)
                    break;
            }
	        j--;
	        
            int num = j-i+1;
            if(num%2==0)ans = ans + num/2;
            else ans = ans + num/2 +1;
            i=j;
            if(j==cards.length)
	               break;
	    }
	    
		return ans;
	}

}
