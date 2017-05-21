public class BearPlaysDiv2 {

    private static boolean[][] visited = new boolean[2000][2000];

    void bruteForce(int x, int y, int z) {
        if (visited[x][y])
            return;
        visited[x][y] = true;

        int a = Math.min(x, Math.min(y, z));
        int b = Math.max(x, Math.max(y, z));
        int c = 0;
        if (x >= a && x <= b)
            c = x;
        if (y >= a && y <= b)
            c = y;
        if (z >= a && z <= b)
            c = z;

        x = a;
        y = c;
        z = b;

        bruteForce(2 * x, y - x, z);
        bruteForce(x, 2 * y, z - y);
        bruteForce(2 * x, 2 * y, z - x);
    }

    public String equalPiles(int A, int B, int C) {
        if ((A + B + C) % 3 != 0)
            return "impossible";
        int mean = (A + B + C) / 3;
        bruteForce(A, B, C);
        if (visited[mean][mean])
            return "possible";
        else {
            return "impossible";
        }
    }
}