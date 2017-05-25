/**
Coding is addictive!!

URL : https://leetcode.com/problems/optimal-division/#/description
Test cases :
No brackets ->
when there is only 1 number
when there are only 2 numbers

Algo :
always direct division of 2nd half will result in max value since denominator will be minimum.
Notes :
Uselessly wasted 2 attempts os submission.
**/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size()==1) return to_string(nums[0]);
        string ans = "";

        for(int i=0;i<nums.size();++i){
            if(i==0){
                ans = ans + to_string(nums[i]);
                if(nums.size()>2)
                    ans = ans + "/(";
                else
                    ans = ans + "/";
            }
            else{
                ans = ans + to_string(nums[i]);
                if(i!=nums.size()-1){
                    ans = ans + "/";
                }
            }
        }
        if(nums.size()>2)
            ans = ans + ")";
        return ans;
    }
};

int main(){
    Solution *s = new Solution();
    cout<<s->
}
