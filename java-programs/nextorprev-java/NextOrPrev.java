public class NextOrPrev {

    public static boolean isIntersecting(String start, String goal) {

        for (int i = 0; i < start.length(); i++) {
            char s = start.charAt(i), e = goal.charAt(i);
            for (int j = 0; j != i && j < start.length(); j++) {
                if ((s >start.charAt(j) && s < goal.charAt(j)) || (e > start.charAt(j) && e < goal.charAt(j)))
                    return true;
            }
        }
        return false;
    }

    public int getMinimum(int nextCost, int prevCost, String start, String goal) {
        int ans = 0;
        if (isIntersecting(start, goal)) {
            return -1;
        }
        for (int i = 0; i < start.length(); i++) {
            if (start.charAt(i) == goal.charAt(i)) {
                continue;
            } else if (start.charAt(i) < goal.charAt(i)) {
                ans = ans + (goal.charAt(i) - start.charAt(i)) * nextCost;
            } else {
                ans = ans + (start.charAt(i) - goal.charAt(i)) * prevCost;
            }
        }
        return ans;
    }

}
