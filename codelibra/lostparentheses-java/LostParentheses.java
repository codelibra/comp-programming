public class LostParentheses {

    public int[] generateArray(String str) {
        int []a = new int[str.length()];
        int j=0;
        for (int i = 0; i < str.length(); i++) {
            String numString = "";
            while(i<str.length() && str.charAt(i)!='+' && str.charAt(i)!='-'){
                numString = numString + str.charAt(i);
                ++i;
            }
        }
        return a;
    }
    public int minResult(String e) {
        int p = e.indexOf('-'),ans=0;
        if (p==-1) p = e.length();
        
        for (int i = 0; i < p; i++) {
            if(e.charAt(i)!='+' && e.charAt(i)!='-')
                ans = ans + (int)e.charAt(i);
        }
        for (int i = p; i < e.length(); i++) {
            if(e.charAt(i)!='+' && e.charAt(i)!='-')
                ans = ans - (int)e.charAt(i);
        }
        
        return ans;
    }

}
