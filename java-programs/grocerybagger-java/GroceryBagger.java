import java.util.HashMap;
import java.util.Map;

public class GroceryBagger {

    public int minimumBags(int strength, String[] itemType) {
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (int i = 0; i < itemType.length; i++) {
            if(map.containsKey(itemType[i])){
                int val = map.get(itemType[i]); 
                map.put(itemType[i], val+1);
            }
            else{
                map.put(itemType[i], 1);
            }
        }
        int ans = 0;
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            String key = entry.getKey();
            Integer value = entry.getValue();
            if(value%strength==0){
                ans = ans + (value/strength);
            }
            else {
                ans = ans+(value/strength) +1;
            }
        }
        return ans;
    }

}
