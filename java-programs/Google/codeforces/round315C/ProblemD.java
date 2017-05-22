package round315C;

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

public class ProblemD {
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

class Node {
    private int sum;
    private int vertex;
    private List<Node> adj;

    public Node(int v, int s) {
        sum = s;
        vertex = v;
        adj = new ArrayList<Node>();
    }

    public int getSum() {
        return sum;
    }

    public int getVetex() {
        return vertex;
    }

    public List<Node> getAdjacent() {
        return adj;
    }

    public void setAdjacent(List<Node> a) {
        adj = a;
    }

    public void setSum(int s) {
        sum = s;
    }

    public void setVertex(int v) {
        vertex = v;
    }
}

class Tree {
    private int V;
    private Node graph[];
    private boolean visited[];
    private long ans;

    public Tree(int N) {
        V = N;
        graph = new Node[N + 1];
        visited = new boolean[N + 1];
        ans = Integer.MIN_VALUE;
    }

    public void travel(long totalSum) {
        graph[1].setSum(traverse(1, totalSum));
    }

    public int traverse(int source, long totalSum) {

        visited[source] = true;

        if (graph[source].getAdjacent().size() == 0)
            return graph[source].getSum();

        int sum = 0;

        for (Node adj : graph[source].getAdjacent()) {
            if (!visited[adj.getVetex()]) {
                int child = traverse(adj.getVetex(), totalSum);
                ans = Math.max(ans, totalSum - child);
                sum = sum + child;
            }
        }

        int temp = sum + graph[source].getSum();
        graph[source].setSum(temp);
        System.out.println(source + " " + ans);
        return temp;
    }

    public void addEdge(int a, int b) {
        Node aa = graph[a];
        aa.getAdjacent().add(graph[b]);
        Node bb = graph[b];
        bb.getAdjacent().add(graph[a]);
    }

    public void setGraphIndex(int i, int sum) {
        Node n = new Node(i, sum);
        graph[i] = n;
    }

    public Node getNode(int n) {
        return graph[n];
    }

    public long getAns() {
        return ans;
    }

    public void printGraph() {
        for (int i = 1; i <= V; i++) {
            System.out.println(graph[i].getVetex() + " " + graph[i].getSum());
        }
    }

}

class Task {

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N = in.nextInt();
        long totalSum = 0;
        Tree tr = new Tree(N);

        for (int i = 1; i <= N; i++) {
            int s = in.nextInt();
            tr.setGraphIndex(i, s);
            totalSum = totalSum + s;
        }

        for (int i = 1; i < N; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            tr.addEdge(a, b);
        }

        tr.travel(totalSum);
        System.out.println(tr.getAns());
        // tr.printGraph();

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