package google;

/**
 * @author panicker
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ProblemB {
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
        int N = in.nextInt(), M = in.nextInt();
        int edges[] = new int[N + 1];
        int graph[][] = new int[N + 1][N + 1];
        int from[] = new int[M + 1];
        int to[] = new int[M + 1];

        for (int i = 0; i < M; i++) {
            int a = in.nextInt();
            int b = in.nextInt();

            graph[a][b] = 1;
            graph[b][a] = 1;

            edges[a]++;
            edges[b]++;
            from[i] = a;
            to[i] = b;
        }

        int minRecognition = Integer.MAX_VALUE;
        boolean found = false;

        for (int i = 0; i < M; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[from[i]][j] == 1 && graph[j][to[i]] == 1) {
                    found = true;
                    minRecognition = Math.min(minRecognition, edges[from[i]] + edges[j] + edges[to[i]] - 6);
                }
            }
        }

        if (!found)
            out.print(-1);
        else
            out.print(minRecognition);

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