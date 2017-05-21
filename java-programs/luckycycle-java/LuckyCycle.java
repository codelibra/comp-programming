public class LuckyCycle {

    public int ansSource;
    public int ansWeight;

    public LuckyCycle() {
        ansSource = -1;
        ansWeight = -1;
    }

    public void dfs(int[][] graph, int visited[], int source, int numfours, int numseven) {
        visited[source] = 1;
        // System.out.println(source);

        for (int i = 0; i < graph[source].length; i++) {
            if (graph[source][i] != 0 && visited[i] == 0) {
                int a = numfours, b = numseven;
                if (graph[source][i] == 4) {
                    if (a == -1)
                        a = 1;
                    else
                        a = numfours + 1;
                }
                if (graph[source][i] == 7) {
                    if (b == -1)
                        b = 1;
                    else
                        b = numseven + 1;
                }

                if (a != b && a != -1 && b != -1 && Math.abs(a - b) == 1) {
                    ansSource = i;
                    if (a > b)
                        ansWeight = 7;
                    else
                        ansWeight = 4;
                    return;

                } else {
                    dfs(graph, visited, i, a, b);
                }
            }
        }
    }

    public int[] getEdge(int[] edge1, int[] edge2, int[] weight) {

        int graph[][] = new int[500][500];
        int N = 1;

        for (int i = 0; i < edge2.length; i++) {
            graph[edge1[i]][edge2[i]] = weight[i];
            if (edge1[i] > N)
                N = edge1[i];
            if (edge2[i] > N)
                N = edge1[i];
        }

        for (int i = 1; i <= N; i++) {
            int visited[] = new int[500];
            dfs(graph, visited, i, -1, -1);
            if (ansSource != -1 && ansWeight != -1) {
                // System.out.println(i + " " + ansSource + " " + ansWeight);
                return new int[] { i, ansSource, ansWeight };
            }
        }
        return new int[0];
    }

}
