package Mashup3;

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

class Pair<A, B> implements Comparable<Pair> {
    private A first;
    private B second;

    public Pair(A first, B second) {
        super();
        this.first = first;
        this.second = second;
    }

    @Override
    public int hashCode() {
        int hashFirst = first != null ? first.hashCode() : 0;
        int hashSecond = second != null ? second.hashCode() : 0;

        return (hashFirst + hashSecond) * hashSecond + hashFirst;
    }

    @Override
    public boolean equals(Object other) {
        if (other instanceof Pair) {
            Pair otherPair = (Pair) other;
            return ((this.first == otherPair.first || (this.first != null && otherPair.first != null && this.first
                    .equals(otherPair.first))) && (this.second == otherPair.second || (this.second != null
                    && otherPair.second != null && this.second.equals(otherPair.second))));
        }

        return false;
    }

    @Override
    public String toString() {
        return "(" + first + ", " + second + ")";
    }

    public A getFirst() {
        return first;
    }

    public void setFirst(A first) {
        this.first = first;
    }

    public B getSecond() {
        return second;
    }

    public void setSecond(B second) {
        this.second = second;
    }

    @Override
    public int compareTo(Pair o) {
        if ((Integer) o.first < (Integer) this.first)
            return 1;
        else
            return -1;
    }
}

class Graph {
    int E;
    int V;
    ArrayList<Pair<Integer, Integer>>[] adjacent;

    public Graph(int v) {
        V = v;
        adjacent = new ArrayList[V + 1];
        for (int i = 0; i <= V; i++) {
            adjacent[i] = new ArrayList<Pair<Integer, Integer>>();
        }
    }

    public int getVertices() {
        return V;
    }

    public int getEdges() {
        return E;
    }

    public void addEdge(int v, int w, int c) {
        adjacent[v].add(new Pair<Integer, Integer>(w, c));
        adjacent[w].add(new Pair<Integer, Integer>(v, c));
    }

    public List<Pair<Integer, Integer>> getAdjacent(int w) {
        return adjacent[w];
    }
}

class DepthFirstSearch {
    boolean[] visited;

    public DepthFirstSearch(Graph g) {
        visited = new boolean[g.getVertices() + 1];
    }

    public boolean dfs(Graph G, int s, int d, int color) {
        visited[s] = true;
        if (s == d) {
            return true;
        }
        List<Pair<Integer, Integer>> adjList = G.getAdjacent(s);

        for (int i = 0; i < adjList.size(); i++) {
            if (!visited[adjList.get(i).getFirst()] && adjList.get(i).getSecond() == color) {
                boolean b = dfs(G, adjList.get(i).getFirst(), d, color);
                if (b == true)
                    return true;
            }
        }
        return false;
    }

}

class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N, M, Q;
        N = in.nextInt();
        M = in.nextInt();
        Graph graph = new Graph(N);
        for (int i = 0; i < M; i++) {
            graph.addEdge(in.nextInt(), in.nextInt(), in.nextInt());
        }

        Q = in.nextInt();
        for (int i = 0; i < Q; i++) {
            int a, b;
            a = in.nextInt();
            b = in.nextInt();
            int ans = 0;
            for (int j = 1; j <= M; j++) {
                DepthFirstSearch depthFirstSearch = new DepthFirstSearch(graph);
                if (depthFirstSearch.dfs(graph, a, b, j))
                    ++ans;
            }
            out.println(ans);
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
