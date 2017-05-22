package Mashup2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class QueB {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N, M;
        N = in.nextInt();

        M = in.nextInt();
        int[][] matrix = new int[N + 1][N + 1];

        for (int j = 1; j <= M; j++) {
            int x = in.nextInt();
            int y = in.nextInt();
            matrix[x][y] = j;
        }

        if (N < 3) {
            System.out.println(-1);
            System.exit(0);
        }

        int ans = -1;
        for (int i = 3; i <= N; i++) {
            for (int j = 3; j <= N; j++) {
                if (matrix[i][j] != 0) {
                    boolean isValid = true;
                    int moves = 0;

                    for (int k = i; k > i - 3; --k) {
                        for (int l = j; l > j - 3; --l) {
                            if (matrix[k][l] == 0)
                                isValid = false;
                            moves = Math.max(moves, matrix[k][l]);
                        }
                    }

                    if (isValid && ans == -1) {
                        ans = moves;

                    } else if (isValid && ans != -1 && moves != 0) {
                        ans = Math.min(ans, moves);
                    }
                }
            }
        }

        System.out.println(ans);

    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}
