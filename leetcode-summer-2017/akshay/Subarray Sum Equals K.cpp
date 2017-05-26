#include<vector>
using namespace std;

class Solution {
public:
    int sum(vector<int>& nums, int i, int j)
    {
      int sum =0;
      for(int k=i; k<=j ; k++)
        sum += nums[k];
      return sum;
    }

    int subarraySum(vector<int>& nums, int k) {

        int count=0;
        for(int i=0; i<nums.size(); i++)
        {
          int sum_i = sum(nums,i,nums.size()-1);
          if(sum_i==k)
            count++;
          for(int j=nums.size()-2; j>=i; j--)
          {
            sum_i = sum_i - nums[j+1];
            if(sum_i==k)
              count++;
          }
        }
        return count;
    }
};
