package Mashup9;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class QueB {
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

class DepthFirstSearch {
    boolean[] visited;
    int[] dp;
    int[] white;

    public DepthFirstSearch(Graph g, int[] w) {
        visited = new boolean[g.getVertices() + 1];
        white = w;
        dp = new int[g.getVertices() + 1];
        dfs(g, 1, 0);
    }

    public void dfs(Graph G, int s, int prev) {
        if (white[s] == 1)
            dp[s] = 1;

        visited[s] = true;

        List<Integer> adjList = G.getAdjacent(s);

        for (int i = 0; i < adjList.size(); i++) {
            if (!visited[adjList.get(i)]) {
                dfs(G, adjList.get(i), s);
                dp[s] = dp[s] + dp[adjList.get(i)];
            }
        }
    }

    public void answer(Graph g) {
        List<Integer> ansIntegers = new ArrayList<Integer>();
        for (int i = 1; i <= g.getVertices(); i++) {
            if (dp[i] == 1) {
                ansIntegers.add(i);
            }
        }
        System.out.println(ansIntegers.size());
        for (int i = 0; i < ansIntegers.size(); i++) {
            System.out.print(ansIntegers.get(i) + " ");
        }
    }
}

class Graph {
    int E;
    int V;
    List<Integer>[] adjacent;

    public Graph(int v) {
        V = v;
        adjacent = new ArrayList[V + 1];
        for (int i = 0; i <= V; i++) {
            adjacent[i] = new ArrayList<Integer>();
        }
    }

    public int getVertices() {
        return V;
    }

    public int getEdges() {
        return E;
    }

    public void addEdge(int v, int w) {
        adjacent[v].add(w);
        adjacent[w].add(v);
    }

    public List<Integer> getAdjacent(int w) {
        return adjacent[w];
    }
}

class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N;
        N = in.nextInt();
        Graph graph = new Graph(N);
        int white[] = new int[N + 1];

        for (int i = 0; i < N - 1; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            graph.addEdge(a, b);
            if (c == 2) {
                white[a] = 1;
                white[b] = 1;
            }
        }

        DepthFirstSearch dfs = new DepthFirstSearch(graph, white);
        dfs.answer(graph);
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

/**
 * simple question actually usage of both dp as well as depth first traversal.
 * depth first traversal used as post order traversal. was able to reduce the
 * problem statement to find the unique ways in which there is 2 in it. also was
 * able to figure out that this will be possible with returning something from
 * the nodes which are visited after should return and the sum should be
 * returned upwards. just that we need to store what was returned to from each
 * node and the ones which return 1 are the ones which were the answers. also
 * there was the problem as to how should i figure out which one is broken. The
 * very easy way is to take another array which is resposible to tell only that
 * a particular thing is one of the broken things or not. Just that using that
 * we can make it as a candidate for answer and then utilize the same for dp.
 * else when to return 1 would have been a problem and we cannot make adjacency
 * matrix since the number of elements is too large for it.
 * 
 */
