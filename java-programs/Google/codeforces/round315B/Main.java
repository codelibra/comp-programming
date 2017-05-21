package round315B;

/*
 * @author panicker
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
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

class UnionFind {
    private int id[];
    private int sz[];

    public UnionFind(int N) {
        id = new int[N + 1];
        sz = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    public boolean connected(int a, int b) {
        return find(a) == find(b);
    }

    public int find(int x) {
        while (id[x] != x) {
            x = id[x];
        }
        return id[x];
    }

    public void union(int x, int y) {
        int p = find(x);
        int q = find(y);

        if (p == q)
            return;

        if (sz[p] > sz[q]) {
            id[q] = id[p];
            sz[p] = sz[p] + sz[q];
        } else {
            id[p] = id[q];
            sz[q] = sz[p] + sz[q];
        }

    }

}

class Task {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        int arr[] = new int[N + 1];
        int ans[] = new int[N + 1];
        int index[] = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            arr[i] = in.nextInt();
            ans[i] = Integer.MAX_VALUE;
            index[arr[i]] = i;
        }

        UnionFind uf = new UnionFind(N);
        for (int i = 1; i <= N; i++) {
            String str = in.next();
            for (int j = 1; j <= N; j++) {
                int b = Integer.valueOf(str.charAt(j - 1) + "");
                if (b == 1) {
                    // System.out.println(i + " " + j);
                    uf.union(i, j);
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            int position = index[i];
            for (int j = 1; j <= N; j++) {
                // System.out.println(i + " " + position + " " + j + " " +
                // uf.connected(position, j));
                if (uf.connected(position, j) && ans[j] > i) {
                    ans[j] = i;
                    break;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            out.print(ans[i] + " ");
        }

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