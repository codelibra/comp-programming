public class EmoticonsDiv2 {

    public int printSmiles(int smiles) {

        int dp[] = new int[2000];

        dp[1] = 0;
        dp[2] = 2;

        for (int i = 0; i < dp.length; i++) {
            dp[i] = i;
        }

        for (int i = 3; i <= smiles; ++i) {
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0)
                    dp[i] = dp[j] + Math.min(dp[i], i / j);
            }
        }
        return dp[smiles];
    }
}
