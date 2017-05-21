package ValidAnagrams;

public class Solution {

    public static void main(String[] args) {
        System.out.println(isAnagram("eat", "tea"));
    }

    public static boolean isAnagram(String s, String t) {
        int count[] = new int[100];
        int count2[] = new int[100];

        if (s.length() != t.length())
            return false;

        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            count2[t.charAt(i) - 'a']++;
        }
        for (int i = 0; i < count2.length; i++) {
            if (count[i] != count2[i])
                return false;
        }
        return true;
    }

}
