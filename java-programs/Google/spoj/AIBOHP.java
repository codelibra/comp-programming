import java.util.Scanner;

class Main {
    public static void main(String[] args) throws java.lang.Exception {
        int dp[][] = new int[6500][6500];

        int t;
        Scanner scanner = new Scanner(System.in);
        t = scanner.nextInt();
        while (t > 0) {
            --t;
            String string = scanner.next();
            int N = string.length();
            for (int len = 1; len < N; ++len) {
                for (int i = 0, j = len; j < N; ++i, ++j) {
                    if (string.charAt(i) != string.charAt(j)) {
                        dp[i][j] = 1 + Math.min(dp[i + 1][j], dp[i][j - 1]);
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
            System.out.println(dp[0][N - 1]);
        }
    }

}