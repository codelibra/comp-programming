public class UnsealTheSafe {

	public long countPasswords(int N) {
	    long dp[][] = new long[10][N+1];
	    int adjacent[][] = new int[10][];
	    adjacent[1] = new int[] {2,4};
	    adjacent[2] = new int[] {1,3,5};
	    adjacent[3] = new int[] {2,6};
	    adjacent[4] = new int[] {1,5,7};
	    adjacent[5] = new int[] {2,4,6,8};
	    adjacent[6] = new int[] {3,5,9};
	    adjacent[7] = new int[] {0,4,8};
	    adjacent[8] = new int[] {5,7,9};
	    adjacent[9] = new int[] {6,8};
	    adjacent[0] = new int[] {7};	    
	    
	    for (int i = 0; i < 10; i++) {dp[i][0] =1;}
	    dp[0][1] = 1;
	    dp[1][1] = 2;
	    dp[2][1] = 3;
	    dp[3][1] = 2;
	    dp[4][1] = 3;
	    dp[5][1] = 4;
	    dp[6][1] = 3;
	    dp[7][1] = 3;
	    dp[8][1] = 3;
	    dp[9][1] = 2;

	    
        for(int j=2; j<=N; ++j){
	    	// calculate the answer of i and then add to ans
            for (int i = 0; i <10; i++) {
                long ansi = 0;
	            for(int k=0; k<adjacent[i].length; ++k){
	                ansi = ansi + dp[adjacent[i][k]][j-1];
	            }
	            dp[i][j] = ansi;
	        }
        }
        long ans = 0;
        for (int i = 0; i < 10; i++) {
            ans = ans + dp[i][N-1];
        }
		return ans;
	}

}
