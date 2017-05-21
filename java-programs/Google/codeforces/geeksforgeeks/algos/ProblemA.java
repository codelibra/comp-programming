package geeksforgeeks.algos;

/**
 * @author panicker
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class ProblemA {
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
    public List<Integer> graph[];
    public int dp[][];// i,j will reprsent the number of nodes at distance j
                      // from ith vertex
    private int K;
    private long ans;
    public int visited[];

    public void dfs(int source) {
        visited[source] = 1;
        dp[source][0] = 1;
        for (int adj : graph[source]) {
            if (visited[adj] == 0) {
                dfs(adj);
                for (int i = 0; i < K; ++i) {
                    ans = ans + dp[source][i] * dp[adj][K - i - 1];
                }
                for (int i = 1; i < K; ++i) {
                    dp[source][i] = dp[source][i] + dp[adj][i - 1];
                }
            }
        }

    }

    public int binarySearch(int arr[], int x) {
        int lo = 0, hi = arr.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] < x) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt(), k = in.nextInt();
        K = k;
        ans = 0;
        visited = new int[N + 1];
        graph = new ArrayList[N + 1];
        dp = new int[N + 1][k];

        for (int i = 0; i <= N; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        for (int i = 1; i < N; i++) {
            int a = in.nextInt(), b = in.nextInt();
            graph[a].add(b);
            graph[b].add(a);
        }
        dfs(1);
        out.print(ans);
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