package GroupAnagrams;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        String[] arrStrings = new String[6];
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < arrStrings.length; i++) {
            arrStrings[i] = scanner.next();
        }
        List<List<String>> ansList = groupAnagrams(arrStrings);
        for (int i = 0; i < ansList.size(); i++) {
            for (int j = 0; j < ansList.get(i).size(); j++) {
                System.out.print(ansList.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    public static List<List<String>> groupAnagrams(String[] strs) {

        Map<String, List<String>> map = new HashMap<String, List<String>>();
        for (int i = 0; i < strs.length; i++) {
            char[] arr = strs[i].toCharArray();
            Arrays.sort(arr);
            String keyString = new String(arr);
            if (map.containsKey(keyString)) {
                List<String> valList = map.get(keyString);
                valList.add(strs[i]);
                map.put(keyString, valList);
            } else {
                List<String> valList = new ArrayList<String>();
                valList.add(strs[i]);
                map.put(keyString, valList);
            }
        }
        List<List<String>> ansList = new ArrayList<List<String>>();
        for (Map.Entry<String, List<String>> entry : map.entrySet()) {
            List<String> ll = entry.getValue();
            Collections.sort(ll);
            ansList.add(ll);
        }
        return ansList;
    }

}
