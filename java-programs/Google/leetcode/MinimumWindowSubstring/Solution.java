package MinimumWindowSubstring;

public class Solution {

    public static void main(String[] args) {
        System.out.println(minWindow("ADOBECODEBANC", "ABC"));
    }

    public static String minWindow(String s, String t) {
        int N = t.length();
        String anString = s;
        int total = t.length();
        int freq[] = new int[2560];
        int currentFreq[] = new int[2560];

        for (int k = 0; k < t.length(); k++) {
            freq[t.charAt(k)]++;
        }

        for (int begin = 0, k = 0; k < s.length(); k++) {
            if (freq[s.charAt(k)] == 0)
                continue;

            currentFreq[s.charAt(k)]++;
            if (freq[s.charAt(k)] >= currentFreq[s.charAt(k)])
                --total;

            if (total == 0) {
                while (currentFreq[s.charAt(begin)] == 0 || currentFreq[s.charAt(begin)] > freq[s.charAt(begin)]) {
                    if (currentFreq[s.charAt(begin)] > freq[s.charAt(begin)])
                        currentFreq[s.charAt(begin)]--;
                    ++begin;
                }
                if (k - begin + 1 < anString.length()) {
                    anString = s.substring(begin, k + 1);
                }
            }
        }

        if (total == 0)
            return anString;
        else
            return "";
    }
}
