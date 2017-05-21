public class TurningLightOn {

    private int flip(int [][] matrix, int i, int j, int N, int M) {
        int ans =0,p=i,q=j;
        while(p<N){
            while(q<M){
                if(matrix[p][q]==1)
                    ans ++;
                ++q;
            }
            ++p;
            q=j;
        }
        return ans;
    }
    public int minFlips(String[] board) {
        int N=board.length , M = board[0].length();
        int [][] matrix = new int[N][M];
        
        int ans = 0;
        for (int i = board.length-1; i >=0; i--) {
            for (int j = board[0].length()-1; j >=0; j--) {
                if(board[i].charAt(j)=='0' && flip(matrix, i, j, N, M)%2==0){
                    matrix[i][j] = 1;
                    ans++;
                }
                if(board[i].charAt(j)=='1' && flip(matrix, i, j, N, M)%2!=0){
                    matrix[i][j] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }

}
