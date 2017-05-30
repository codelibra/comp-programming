#include<vector>
using namespace std;

class Solution {
public:
  int rob1(vector<int>& nums)
    {
      int n = nums.size();
      vector<int> dp(n,0);

      for(int i=0; i<n; i++)
      {
        dp[i] = nums[i];
        int max = 0;
        for(int j=i-2; j>=0; j--)
        {
          if(max<dp[j])
            max = dp[j];
        }
        dp[i] = dp[i] + max;
      }

      int max = 0;
      for(int i=0;i<n;i++)
      {
        if(max<dp[i])
          max = dp[i];
      }

      return max;
    }

    int rob(vector<int>& nums)
    {
      if(nums.size()==0)
        return 0;

      vector<int> notLast(nums.begin(),nums.end()-1);
      int excludingLast = rob1(notLast);

      vector<int> notFirst(nums.begin()+1,nums.end());
      int excludingFirst = rob1(notFirst);
      return max(excludingLast,excludingFirst);
    }
};
