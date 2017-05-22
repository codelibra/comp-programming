package Mashup8;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class QueC {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }
}

class Task {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N, M;
        N = in.nextInt();
        M = in.nextInt();
        int graph[][] = new int[N + 1][N + 1];
        int[] degree = new int[N + 1];

        for (int i = 0; i < M; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            graph[a][b] = 1;
            graph[b][a] = 1;
            degree[a]++;
            degree[b]++;
        }
        int ans = 0;
        while (true) {
            List<Integer> arrIntegers = new ArrayList<Integer>();

            for (int j = 1; j <= N; ++j) {
                if (degree[j] == 1) {
                    arrIntegers.add(j);
                }
            }
            if (arrIntegers.size() == 0)
                break;

            ans = ans + 1;
            for (int i = 0; i < arrIntegers.size(); i++) {
                degree[arrIntegers.get(i)]--;
                for (int j = 1; j <= N; j++) {
                    if (graph[arrIntegers.get(i)][j] == 1) {
                        graph[arrIntegers.get(i)][j] = 0;
                        degree[j]--;
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
