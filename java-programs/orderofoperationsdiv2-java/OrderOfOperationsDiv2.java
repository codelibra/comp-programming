public class OrderOfOperationsDiv2 {

    private boolean visited[];
    private boolean visitedColumn[];
    private int count;
    private int cost;

    public int minUnvisited(String[] s) {
        int index = 0;
        int minVisited = s[0].length();
        for (int i = 0; i < s.length; i++) {
            if (visitedColumn[i] == true)
                continue;
            String str = s[i];
            int val = 0;
            for (int j = 0; j < str.length(); j++) {
                if (str.charAt(j) == '1' && visited[j] == false) {
                    ++val;
                }
            }
            if (val < minVisited) {
                minVisited = val;
                index = i;
            }
        }
        ++count;
        return index;
    }

    public void visit(String[] s, int index) {
        String str = s[index];
        int val = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '1' && visited[i] == false) {
                visited[i] = true;
                ++val;
            }
        }
        cost = cost + val * val;
    }

    public int minTime(String[] s) {
        visited = new boolean[s[0].length()];
        visitedColumn = new boolean[s.length];
        cost = 0;
        while (count < s.length) {
            int index = minUnvisited(s);
            visitedColumn[index] = true;
            // System.out.println(s[index]);
            visit(s, index);
        }
        return cost;
    }

}
