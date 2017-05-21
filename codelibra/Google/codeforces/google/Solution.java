package google;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Stack;

class Graph {
    private final int V;
    private int E;
    private List<Integer> Graph[];

    public Graph(int V) {
        this.V = V;
        Graph = new ArrayList[V];
        E = 0;
    }

    public int getVertices() {
        return V;
    }

    public int getEdges() {
        return E;
    }

    public void addEdge(int a, int b) {
        Graph[a].add(b);
        Graph[b].add(a);
        E++;
    }

    public List<Integer> adjacent(int d) {
        return Graph[d];
    }
}

class DepthFirstSearch {

    private boolean[] visited;
    private int[] edgeTo;
    private final int source;

    public DepthFirstSearch(int source, Graph G) {
        this.source = source;
        visited = new boolean[G.getVertices()];
        edgeTo = new int[G.getVertices()];
        dfs(G, source);
    }

    private void dfs(Graph g, int s) {
        visited[s] = true;
        for (int v : g.adjacent(s)) {
            if (!visited[v]) {
                edgeTo[v] = s;
                dfs(g, v);
            }
        }
    }

    public boolean hasPathTo(int v) {
        return visited[v];
    }

    public List<Integer> pathTo(int v) {
        List<Integer> path = new ArrayList<Integer>();

        for (int x = v; x != source; x = edgeTo[x])
            path.add(x);
        path.add(source);
        return path;
    }
}

class BredthFirstSearch {

    private boolean[] visited;
    private int[] edgeTo;
    private int[] pathTo;
    private int source;

    public BredthFirstSearch(int source, Graph g) {
        visited = new boolean[g.getVertices()];
        pathTo = new int[g.getVertices()];
        bfs(g, source);
    }

    private void bfs(Graph g, int s) {
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(s);
        visited[s] = true;

        while (!queue.isEmpty()) {
            int v = queue.poll();
            List<Integer> adjacent = g.adjacent(v);
            for (int adj : adjacent) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    edgeTo[adj] = v;
                    queue.add(adj);
                }
            }
        }
    }

    public boolean hasPathTo(int v) {
        return visited[v];
    }

    public List<Integer> pathTo(int v) {
        List<Integer> path = new ArrayList<Integer>();
        for (int x = v; x != source; x = edgeTo[x]) {
            path.add(x);
        }
        return path;
    }
}

class ConnectedComponent {

    private boolean visited[];
    private int id[];
    private int count;

    public ConnectedComponent(Graph G) {
        id = new int[G.getVertices()];
        visited = new boolean[G.getVertices()];
        count = 0;
        for (int i = 0; i < G.getVertices(); ++i) {
            if (!visited[i]) {
                dfs(G, i);
                count++;
            }
        }
    }

    public void dfs(Graph g, int s) {
        visited[s] = true;
        id[s] = count;

        for (int adj : g.adjacent(s)) {
            if (!visited[adj]) {
                dfs(g, adj);
            }
        }
    }

    public boolean isSameComponent(int a, int b) {
        return id[a] == id[b];
    }

    public int numberOfComponents() {
        return count;
    }

}

class Cycle {
    private boolean visited[];
    private boolean hasCycle;

    public Cycle(Graph g) {
        visited = new boolean[g.getVertices()];
        for (int i = 0; i < g.getVertices(); ++i) {
            if (!visited[i]) {
                dfs(g, i, i);
            }
        }
    }

    private void dfs(Graph g, int d, int s) {
        visited[d] = true;

        for (int adj : g.adjacent(d)) {
            if (!visited[adj])
                dfs(g, adj, d);
            else {
                if (adj != s)
                    hasCycle = true;
            }
        }
    }

    public boolean hasCycle() {
        return this.hasCycle;
    }
}

class Bipartite {

    private boolean visited[];
    private boolean color[];
    private boolean isBipartite;

    public Bipartite(Graph g) {
        visited = new boolean[g.getVertices()];
        color = new boolean[g.getVertices()];
        isBipartite = true;
        for (int i = 0; i < g.getVertices(); ++i) {
            if (!visited[i])
                dfs(g, i);
        }
    }

    public void dfs(Graph g, int source) {
        visited[source] = true;

        for (int adj : g.adjacent(source)) {
            if (!visited[adj]) {
                color[adj] = !color[source];
                dfs(g, adj);
            } else {
                if (color[adj] == color[source])
                    isBipartite = false;
            }
        }
    }

    public boolean isBipartite() {
        return isBipartite;
    }

}

class Diagraph {

    private final int V;
    private int E;
    private List<Integer> graph[];

    public Diagraph(int v) {
        this.V = v;
        graph = new ArrayList[V];
    }

    public void addEdge(int a, int b) {
        graph[a].add(b);
        ++E;
    }

    public int getVertices() {
        return V;
    }

    public int getEdges() {
        return E;
    }

    public List<Integer> getAdjacent(int s) {
        return graph[s];
    }

    public Diagraph reverseDiagraph() {
        Diagraph reverse = new Diagraph(V);

        for (int i = 0; i < V; ++i) {
            for (int adj : getAdjacent(i)) {
                reverse.addEdge(adj, i);
            }
        }
        return reverse;
    }
}

class DirectedDFS {
    private boolean visited[];
    private int edgeTo[];
    private int source;
    private Queue<Integer> preorder;
    private Queue<Integer> postorder;
    private Stack<Integer> reversePosrOrder;

    public DirectedDFS(Diagraph g, int s) {
        visited = new boolean[g.getVertices()];
        edgeTo = new int[g.getVertices()];
        source = s;

        dfs(g, s);
    }

    public void dfs(Diagraph g, int source) {
        visited[source] = true;
        preorder.add(source);
        for (int adj : g.getAdjacent(source)) {
            if (!visited[adj]) {
                edgeTo[adj] = source;
                dfs(g, adj);
            }
        }
        postorder.add(source);
        reversePosrOrder.add(source);
    }

    public Stack<Integer> topologicalSort() {
        return reversePosrOrder;
    }

    public boolean isReachable(int v) {
        return visited[v];
    }

    public List<Integer> path(int v) {
        if (!isReachable(v))
            return null;

        List<Integer> path = new ArrayList<Integer>();
        for (int x = v; x != source; x = edgeTo[x])
            path.add(x);
        return path;
    }

}

class DirectedCycle {
    private boolean visited[];
    private boolean onStack[];
    private boolean isCyclic;

    public DirectedCycle(Diagraph g) {
        visited = new boolean[g.getVertices()];
        onStack = new boolean[g.getVertices()];
        isCyclic = false;

        for (int i = 0; i < g.getVertices(); ++i)
            dfs(g, i);
    }

    public void dfs(Diagraph g, int source) {
        visited[source] = true;
        onStack[source] = true;

        for (int adj : g.getAdjacent(source)) {
            if (!visited[adj]) {
                dfs(g, adj);
            } else {
                if (onStack[adj])
                    isCyclic = true;
            }
        }
        onStack[source] = false;
    }

    public boolean hasCycle() {
        return isCyclic;
    }
}

class DirectedStronglyConnectedComponents {
    private boolean visited[];
    private int id[];
    private int count;

    public DirectedStronglyConnectedComponents(Diagraph g) {
        visited = new boolean[g.getVertices()];
        id = new int[g.getVertices()];
        DirectedDFS dfs = new DirectedDFS(g.reverseDiagraph(), 0);
        for (int order : dfs.topologicalSort()) {
            if (!visited[order]) {
                dfs(g, order);
                ++count;
            }
        }
    }

    private void dfs(Diagraph g, int s) {
        visited[s] = true;
        id[s] = count;

        for (int adj : g.getAdjacent(s)) {
            if (!visited[adj]) {
                dfs(g, adj);
            }
        }
    }
}

class Edge implements Comparable<Edge> {
    private int v;
    private int w;
    private int weight;

    public Edge(int a, int b, int m) {
        v = a;
        w = b;
        weight = m;
    }

    public int getWeight() {
        return weight;
    }

    public int getEither() {
        return v;
    }

    public int getOther() {
        return w;
    }

    @Override
    public int compareTo(Edge other) {
        if (weight < other.getWeight())
            return -1;
        else if (weight > other.getWeight())
            return 1;
        else
            return 0;
    }

}

class EdgeWeightedDigraph {

    private List<Edge> graph[];
    private final int V;
    private int E;

    public EdgeWeightedDigraph(int v) {
        this.V = v;
        E = 0;
        graph = new ArrayList[v];
    }

    public void addEdge(int a, int b, int w) {
        graph[a].add(new Edge(a, b, w));
        ++E;
    }

    public List<Edge> adjacent(int a) {
        return graph[a];
    }

    public int getVertices() {
        return V;
    }

}

class MinimiumSpanningTreePrims {

    private List<Edge> mst;
    private PriorityQueue<Edge> pq;
    private boolean visited[];

    public MinimiumSpanningTreePrims(EdgeWeightedDigraph g) {
        visited = new boolean[g.getVertices()];
        visited[0] = true;
        pq = new PriorityQueue<Edge>();
        visit(g, 0);
        while (!pq.isEmpty()) {
            Edge top = pq.poll();
            int a = top.getEither();
            int b = top.getOther();
            if (visited[a] && visited[b])
                continue;
            mst.add(top);

            if (!visited[a])
                visit(g, a);
            if (!visited[b])
                visit(g, b);
        }
    }

    public void visit(EdgeWeightedDigraph g, int v) {
        visited[v] = true;
        for (Edge adj : g.adjacent(v)) {
            int u = adj.getOther();
            int k = adj.getEither();
            if (u != v && !visited[u]) {
                pq.add(adj);
            }
            if (k != v && !visited[k]) {
                pq.add(adj);
            }
        }
    }

}

class UnionFind {
    private int id[];
    private int sz[];
    private int count;

    public UnionFind(int N) {
        id = new int[N];
        sz = new int[N];

        for (int i = 0; i < N; ++i) {
            id[i] = i;
            sz[i] = 1;
        }
        count = N;
    }

    public boolean isConnected(int i, int j) {
        return id[i] == id[j];
    }

    public int find(int w) {
        while (id[w] != w)
            w = id[w];
        return w;
    }

    public void union(int a, int b) {
        int p = find(a);
        int q = find(b);

        if (p == q)
            return;
        if (sz[p] < sz[q]) {
            id[p] = q;
            sz[q] = sz[q] + sz[p];
        } else {
            id[q] = p;
            sz[p] = sz[q] + sz[p];
        }
        --count;
    }

    public int connectedComponents() {
        return count;
    }
}

class MinimumSpanningTreeKruskal {
    private PriorityQueue<Edge> pqEdges;
    private Stack<Edge> mst;

    public MinimumSpanningTreeKruskal(EdgeWeightedDigraph g, int v) {
        pqEdges = new PriorityQueue<Edge>();
        UnionFind uf = new UnionFind(g.getVertices());
        for (int i = 0; i < v; i++) {
            for (Edge adj : g.adjacent(i)) {
                pqEdges.add(adj);
            }
        }

        while (!pqEdges.isEmpty()) {
            Edge top = pqEdges.peek();
            int a = top.getEither();
            int b = top.getOther();
            if (uf.isConnected(a, b))
                continue;
            mst.add(top);
            uf.union(a, b);
        }
    }

    public Stack<Edge> MST() {
        return mst;
    }
}

class DirectedEdge {
    private int from;
    private int to;
    private int weight;

    public DirectedEdge() {

    }

    public DirectedEdge(int a, int b, int c) {
        from = a;
        to = b;
        weight = c;
    }

    public int from() {
        return from;
    }

    public int tp() {
        return to;
    }

    public int weight() {
        return weight;
    }

}

class EdgeWeightedDiagraph {

    private List<DirectedEdge> graph[];
    private int V;
    private int E;

    public EdgeWeightedDiagraph(int v) {
        graph = new ArrayList[v];
        V = v;
        E = 0;
    }

    public int getVertices() {
        return V;
    }

    public void addEdge(int a, int b, int w) {
        DirectedEdge d = new DirectedEdge(a, b, w);
        graph[a].add(d);
        ++E;
    }

    private int getEdges() {
        return E;
    }

}

class ShortestPaths {
    private DirectedEdge[] edgeTo;
    private int[] distTo;

    private void relax(DirectedEdge e) {
        int a = e.from(), b = e.tp();

        if (distTo[b] > distTo[a] + e.weight()) {
            distTo[b] = distTo[a] + e.weight();
            edgeTo[b] = new DirectedEdge(a, b, e.weight());
        }

    }

    public ShortestPaths(EdgeWeightedDigraph g, int source) {
        edgeTo = new DirectedEdge[g.getVertices()];
        distTo = new int[g.getVertices()];

        for (int i = 0; i < g.getVertices(); ++i)
            distTo[i] = Integer.MAX_VALUE;
        distTo[0] = 0;

        DirectedDFS dfs = new DirectedDFS(g, source);
        Stack<Integer> toplogical = dfs.topologicalSort();

        while (!toplogical.isEmpty()) {
            for (Edge adj : g.adjacent(toplogical.pop())) {
                relax(adj);
            }
        }
    }
}

public class Solution {

    private TreeNode first;
    private TreeNode middle;
    private TreeNode last;
    private TreeNode prev;

    public void CorrectTree(TreeNode node) {

        if (node != null) {
            CorrectTree(node.left);
            if (prev != null && node.val < prev.val) {
                if (first != null) {
                    first = prev;
                    middle = node;
                } else {
                    last = node;
                }
            }
            prev = node;
            CorrectTree(node.right);
        }
    }

    public void recoverTree(TreeNode root) {
        first = null;
        middle = null;
        last = null;
        prev = null;
        CorrectTree(root);
        if (first != null && last != null) {
            int temp = first.val;
            last.val = first.val;
            first.val = temp;
        } else {
            int temp = first.val;
            first.val = middle.val;
            middle.val = temp;
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(10);
        root.left = new TreeNode(8);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(2);
    }
}

class TreeLinkNode {
    int val;
    TreeLinkNode left, right, next;

    TreeLinkNode(int x) {
        val = x;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Meta {
    int min;
    int max;
    boolean isBST;

    void setMin(int m) {
        this.min = m;
    }

    void setMax(int m) {
        this.max = m;
    }

    void setIsBST(boolean m) {
        isBST = m;
    }

    int getMin() {
        return this.min;
    }

    int getMax() {
        return this.max;
    }

    boolean getIsBST() {
        return isBST;
    }

    public Meta(int c, int b, boolean a) {
        this.min = c;
        this.max = b;
        this.isBST = a;
    }
}
