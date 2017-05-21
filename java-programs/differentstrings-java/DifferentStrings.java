public class DifferentStrings {

    public int minimize(String A, String B) {
        int ans=B.length();
        int N = B.length() - A.length();

        for (int i = 0; i <= N; i++) {
            int diff = 0;
            for (int j = i; j < A.length()+i; j++) {
                if(A.charAt(j-i) !=B.charAt(j)) ++diff;
                System.out.println(A.charAt(j-i) +" "+B.charAt(j));
            }
            if(ans>diff)
                ans = diff;
        }
        return ans;
    }

}
