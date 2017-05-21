public class PointDistance {

    public double distance(int x, int y, int p, int q) {
        return Math.sqrt(Math.pow(x - p, 2) + Math.pow(y - q, 2));
    }

    public int[] findPoint(int x1, int y1, int x2, int y2) {

        int ans[] = new int[2];
        for (int x = -100; x <= 100; ++x) {
            for (int y = -100; y <= 100; ++y) {

                if (distance(x1, y1, x, y) > distance(x2, y2, x, y)) {
                    if (x != x1 && x != x2 && y != y1 && y != y2) {
                        ans[0] = x;
                        ans[1] = y;
                        return ans;
                    }
                }
            }
        }
        return ans;
    }

}
