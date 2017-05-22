public class ThePalindrome {

    public static boolean isPalindromeCenter(int index, String str) {
        int i=index+1, j=index-1;
        while(i<str.length() && j>=0){
            if(str.charAt(i)!=str.charAt(j))
                return false;
            ++i;
            --j;
        }
        if(i<str.length() && j<0)
            return false;
        return true;
    }
    public static boolean  isPalindromePart(int index, String str) {
        int i=index, j=index-1;
        while(i<str.length() && j>=0){
            if(str.charAt(i)!=str.charAt(j))
                return false;
            ++i;
            --j;
        }
        if(i<str.length() && j<0)
            return false;
        return true;
    }
	public int find(String s) {
	    int j=s.length()-1, N=s.length(), ans=2*N;

	    while (j>=(N/2)){
	        if(isPalindromeCenter(j, s)){
	            ans = Math.min(2*j+1, ans);
	        }
	        if(isPalindromePart(j, s)){
	            ans = Math.min(2*j, ans);
	        }
	        --j;
	    }
	    if(ans ==0) ans = N;
		return ans;
	}

}
