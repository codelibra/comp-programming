/**
Coding is addictive!!

URL : https://leetcode.com/problems/subarray-sum-equals-k/#/description
Test cases :
Algo :
Notes :
**/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long int arr[100000], sum =0, currentSum=0, ans=0;
        for(int i=0;i<nums.size();++i){
            sum = sum + nums[i];
            arr[i] = sum;
        }

        for(int i=0;i<nums.size();++i){
            for(int j=i;j<nums.size();++j){
                currentSum = arr[j] - arr[i] + nums[i];
                if(currentSum == k){
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution *s = new Solution();
    vector<int> v;v.push_back(1);v.push_back(1);v.push_back(1);
    cout<<s->subarraySum(v,2);
}
