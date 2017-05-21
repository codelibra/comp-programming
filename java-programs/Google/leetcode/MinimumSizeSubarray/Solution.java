package MinimumSizeSubarray;

public class Solution {
    public static void main(String[] args) {
        System.out.println(minSubArrayLen(4, new int[] { 1, 4, 4 }));
    }

    public static int minSubArrayLen(int s, int[] nums) {

        int i = 0, j = 0;
        int sum = 0;
        int ans = Integer.MAX_VALUE;
        boolean found = false;
        while (j < nums.length) {
            while (j < nums.length && sum <= s) {
                sum = sum + nums[j++];
                if (sum == s && j - i < ans) {
                    ans = j - i;
                    found = true;
                }
            }

            while (i < nums.length && sum >= s) {
                if (j - i < ans) {
                    ans = j - i;
                    found = true;
                }

                sum = sum - nums[i++];
            }
        }
        if (!found)
            return 0;
        return ans;
    }
}
