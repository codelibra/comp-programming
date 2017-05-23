/**
Coding is addictive!!

URL : https://leetcode.com/problems/longest-harmonious-subsequence/#/description
Test cases :
check if there is none with distance 1
check absolute distance
Algo :
count array -> count of each number
max len -> max length array which can be made using this number
max len[i] = max ( count [i] + count [i-1] , count[i] + count[i+1])
return max of this array

Notes :
Did not read the question carefully and screwed up the initial algo too much.
**/

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLength[20000]={-1}, ans=0, currentMax = 0;
        map<int,int> counts;

        for(int i=0;i<nums.size();++i){
            if(counts.find(nums[i])==counts.end()){
                counts[nums[i]] =1;
            }
            else{
                counts[nums[i]] = counts[nums[i]] + 1;
            }
        }

        for(int i=0;i<nums.size();++i){
            if(counts.find(nums[i]-1)!=counts.end()){
                currentMax = max(currentMax, counts[nums[i]]+counts[nums[i]-1]);
            }

            if(counts.find(nums[i]+1)!=counts.end()){
                currentMax = max(currentMax, counts[nums[i]]+counts[nums[i]+1]);
            }

            if(ans<currentMax){
                ans = currentMax;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    Solution *s = new Solution();
    cout<<s->findLHS(v);
}
