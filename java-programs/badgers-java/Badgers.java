public class Badgers {

    public int minimumUnvisited(int[]visited, int []greed){
        int ans = -1, val = Integer.MAX_VALUE;
        for (int i = 0; i < greed.length; i++) {
            if(val>greed[i] && visited[i]==0){
                val = greed[i];
                ans = i;
            }
        }
        return ans;
    }
    
    public int feedMost(int[] hunger, int[] greed, int totalFood) {
        int []visited = new int[greed.length];
        int greedSum=0;
        int ans = 1;
        while(true){
            int index = minimumUnvisited(visited, greed);
            greedSum = greedSum + greed[index];
            if((totalFood-hunger[index]) - (ans*greedSum)>0){
                totalFood = totalFood - hunger[index];
                visited[index] = 1;
                ans = ans + 1;
            }
            else {
                break;
            }
        }
        return ans;
    }

}
