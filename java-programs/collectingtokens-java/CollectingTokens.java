import java.util.ArrayList;
import java.util.List;

public class CollectingTokens {

    private int max;
    private boolean visited[];
    private List<Integer> graph[];

    private void dfs(int L, int V, int[] tokens) {
        for (int i = 1; i <= V; ++i) {
            if (!visited[i]) {
                visit(i, 0, L, tokens[i], tokens);
            }
        }
    }

    private void visit(int vertex, int e, int L, int sum, int[] tokens) {
        visited[vertex] = true;

        if (e >= L) {
            max = Math.max(sum, max);
            return;
        }

        for (int adj : graph[vertex]) {
            if (!visited[adj]) {
                visit(adj, e + 1, L, sum + tokens[adj], tokens);
            }
        }

    }

    public int maxTokens(int[] A, int[] B, int[] tokens, int L) {
        graph = new ArrayList[100];
        visited = new boolean[100];
        int v = 1;

        for (int i = 0; i < 100; i++)
            graph[i] = new ArrayList<Integer>();

        for (int i = 0; i < A.length; i++) {
            graph[A[i]].add(B[i]);
            graph[B[i]].add(A[i]);
            v = Math.max(v, A[i]);
            v = Math.max(v, B[i]);
        }
        dfs(L, v, tokens);
        return max;
    }

}
