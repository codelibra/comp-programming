public class DevuAndGame {

    public String canWin(int[] nextLevel) {
        boolean visited[] = new boolean[nextLevel.length];

        for (int x = 0; x != -1;) {
            if (visited[x] == true)
                return "Lose";
            visited[x] = true;
            x = nextLevel[x];
        }

        return "Win";
    }

}
