public class GearsDiv2 {

    public static int min(String Directions) {
        System.out.println(Directions);
        int ans =0;
        for (int i = 1; i < Directions.length(); i++) {
            if(Directions.charAt(i)==Directions.charAt(i-1)){
                Directions = Directions.substring(0, i)+ "X" + Directions.substring(i+1, Directions.length());
                ans = ans +1;
            }
        }
        return ans;
    }
    public int getmin(String Directions) {
        if(Directions.charAt(0)==Directions.charAt(Directions.length()-1)){
            int a= min(Directions.substring(1));
            int b = min(Directions.substring(0, Directions.length()-1));
            return Math.min(a, b)+1;
        }
        return min(Directions);
    }

}
