import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class SmartWordToy {

    public boolean hash[][][][][];

    public boolean checkForbidden(String[] forbid, String str) {
        if (forbid.length == 0)
            return false;

        for (int i = 0; i < hash.length; i++) {
            if (hash[i][str.charAt(0) - 'a'][str.charAt(1) - 'a'][str.charAt(2) - 'a'][str.charAt(3) - 'a'])
                return true;
        }
        return false;
    }

    private void preprocess(String[] forbid) {
        hash = new boolean[50][26][26][26][26];
        for (int i = 0; i < forbid.length; i++) {
            String splits[] = forbid[i].split("\\s+");
            for (int j = 0; j < splits.length; j++) {
                for (int j2 = 0; j2 < splits[j].length(); j2++) {
                    if (j == 0)
                        hash[i][splits[j].charAt(j2) - 'a'][j][j][j] = true;
                    if (j == 1)
                        hash[i][j][splits[j].charAt(j2) - 'a'][j][j] = true;
                    if (j == 2)
                        hash[i][j][j][splits[j].charAt(j2) - 'a'][j] = true;
                    if (j == 3)
                        hash[i][j][j][j][splits[j].charAt(j2) - 'a'] = true;
                }
            }
        }
    }

    public int minPresses(String start, String finish, String[] forbid) {
        preprocess(forbid);
        Queue<String> queue = new LinkedList<String>();
        HashSet<String> visited = new HashSet<String>();
        queue.add(start);
        queue.add(null);
        int count = 0;

        while (!queue.isEmpty()) {
            String top = queue.poll();

            if (top == null) {
                if (!queue.isEmpty()) {
                    queue.add(null);
                    ++count;
                    continue;
                } else
                    break;
            }
            if (top.compareTo(finish) == 0) {
                return count;
            }
            visited.add(top);
            // System.out.println(top);
            char arr[] = top.toCharArray();
            for (int i = 0; i < arr.length; ++i) {
                char temp = arr[i], next = (char) (arr[i] + 1), prev = (char) (arr[i] - 1);

                if (temp == 'a')
                    prev = 'z';
                if (temp == 'z')
                    next = 'a';

                arr[i] = next;
                String str = new String(arr);
                if (!visited.contains(str) && !checkForbidden(forbid, str))
                    queue.add(str);

                arr[i] = prev;
                String str2 = new String(arr);
                if (!visited.contains(str2) && !checkForbidden(forbid, str2))
                    queue.add(str2);

                arr[i] = temp;
            }

        }
        return -1;
    }
}
