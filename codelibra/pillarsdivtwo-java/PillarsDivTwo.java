public class PillarsDivTwo {

    public double lengthCalculate(int a, int b, int w) {
        return Math.sqrt(Math.pow(w, 2) + Math.pow(b - a, 2));
    }

    public double maximalLength(int[] height, int w) {
        int N = height.length;
        double dp[][] = new double[1000][1000];

        for (int i = 0; i <= N - 2; i++) {
            for (int k = 1; k <= height[i]; k++) {
                for (int j = 1; j <= height[i + 1]; j++) {
                    dp[i + 1][j] = Math.max(lengthCalculate(k, j, w) + dp[i][k], dp[i + 1][j]);
                }
            }
        }

        double maxi = 0;
        for (int i = 1; i <= height[N - 1]; i++) {
            maxi = Math.max(dp[N - 1][i], maxi);
        }
        return maxi;
    }
}
