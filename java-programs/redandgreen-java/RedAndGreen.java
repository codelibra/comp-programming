public class RedAndGreen {

    private int mismatch(String a, String b) {
        int ans=0;
        for (int i = 0; i < a.length(); i++) {
            if(a.charAt(i)!=b.charAt(i))
                ++ans;
        }
        return ans;
    }
    public int minPaints(String row) {
        int i=0, j=row.length()-1,ans = Integer.MAX_VALUE;
        String test = "";
        for (int k = 0; k < row.length(); k++) {
            test = test + 'G';        
        }
        ans = Math.min(ans, mismatch(test, row));
        for (int k2 = 0; k2 < row.length(); k2++) {
            test = test.substring(0,k2)+'R'+test.substring(k2+1);
            ans = Math.min(ans, mismatch(test, row));
        }
        return ans;
    }

}
