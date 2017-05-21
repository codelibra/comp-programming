public class Time {

    public String whatTime(int seconds) {

        int h = 0, m = 0, s = 0;
        int total = 86399;
        while (seconds > 0 && seconds <= total) {
            s = s + 1;
            seconds = seconds - 1;
            if (s == 60) {
                s = 0;
                m = m + 1;
            }
            if (m == 60) {
                h = h + 1;
                m = 0;
            }
        }
        String ans = Integer.toString(h) + ":" + Integer.toString(m) + ":" + Integer.toString(s);
        return ans;
    }

}
