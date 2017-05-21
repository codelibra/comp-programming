package geeksforgeeks.algos;

public class LongestCommonSubsequence {

    public static String LCS(String aString, String bString) {
        int dp[][] = new int[aString.length() + 1][bString.length() + 1];
        String string = null;
        String[][] ans = new String[aString.length() + 1][bString.length() + 1];

        for (int i = 0; i <= aString.length(); i++) {
            for (int j = 0; j <= bString.length(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                    ans[i][j] = "";
                }

                else if (aString.charAt(i - 1) == bString.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans[i][j] = aString.charAt(i - 1) + ans[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    if (dp[i - 1][j] > dp[i][j - 1])
                        ans[i][j] = (ans[i - 1][j]);
                    else
                        ans[i][j] = (ans[i][j - 1]);
                }
            }
        }
        System.out.println(ans[aString.length()][bString.length()]);
        return string;

    }

    public static void main(String[] args) {
        String xString = "AGGTAB", yString = "GXTXAYB";
        LCS(xString, yString);
    }
}
