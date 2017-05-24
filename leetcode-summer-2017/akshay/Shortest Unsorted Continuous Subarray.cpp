#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin() ,sorted.end());

        int i;
        for(i=0;i<nums.size();i++)
        {
          if(sorted[i] != nums[i])
            break;
        }

        int j;
        for(j=nums.size()-1;j>=0;j--)
        {
          if(sorted[j] != nums[j])
            break;
        }

        if(i>=j)
          return 0;

        return j-i+1;
    }
};
