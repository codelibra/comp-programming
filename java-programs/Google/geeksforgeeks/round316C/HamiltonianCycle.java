package round316C;

/**
 * Given a graph, find whether it contains a hamiltonian cycle. What is a
 * hamiltonian cycle? A cycle which will contain all the vertices of the graph
 * with the exception that, the path will visit all the vertices of the graph
 * only once.
 * 
 * @author shiv
 *
 */
public class HamiltonianCycle {
    private static int path[];
    private static int V;

    private static boolean isSafe(int[][] graph, int v, int pos) {
        if (graph[pos - 1][v] == 0)
            return false;

        for (int i = 0; i < pos - 1; ++i)
            if (path[i] == v)
                return false;
        return true;
    }

    private static boolean hamCycleGenerate(int[][] graph, int pos) {
        if (pos == V) {
            if (graph[pos - 1][0] == 0)
                return false;
            else
                return true;
        }

        for (int v = 1; v < V; ++v) {
            if (isSafe(graph, v, pos)) {
                path[pos] = v;

                if (hamCycleGenerate(graph, pos + 1) == true)
                    return true;

                path[pos] = -1;
            }
        }

        return false;
    }

    private static void hamCycle(int[][] graph) {
        path = new int[graph.length];
        path[0] = 0;

        hamCycleGenerate(graph, 1);
    }

    public static void main(String[] args) {
        int graph1[][] = { { 0, 1, 0, 1, 0 }, { 1, 0, 1, 1, 1 }, { 0, 1, 0, 0, 1 }, { 1, 1, 0, 0, 1 },
                { 0, 1, 1, 1, 0 } };
        V = graph1.length;
        hamCycle(graph1);
    }
}
