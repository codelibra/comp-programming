public class PalindromicSubstringsDiv2 {

    public int count(String[] S1, String[] S2) {

        String string = "";
        for (int i = 0; i < S1.length; i++) {
            string = string + S1[i];
        }

        for (int j = 0; j < S2.length; j++) {
            string = string + S2[j];
        }

        int dp[][] = new int[string.length() + 1][string.length() + 1];
        int num = 0;

        for (int lenght = 1; lenght <= string.length(); lenght++) {
            for (int i = 0, j = i + lenght - 1; j < string.length(); i++, j++) {
                if (lenght == 1) {
                    dp[i][j] = 1;
                    ++num;
                    continue;
                }
                if (lenght == 2 && string.charAt(i) == string.charAt(j)) {
                    dp[i][j] = 1;
                    ++num;
                    continue;
                } else if (string.charAt(i) == string.charAt(j) && dp[i + 1][j - 1] != 0) {
                    dp[i][j] = 1;
                    ++num;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return num;
    }
}
