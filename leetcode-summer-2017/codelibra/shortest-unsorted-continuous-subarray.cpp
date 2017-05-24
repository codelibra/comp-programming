/**
Coding is addictive!!

URL : https://leetcode.com/problems/shortest-unsorted-continuous-subarray/#/description
Test cases :
Catch the test-case when there is no such array!
test case when middle array has elements smaller/larger than the outer already sorted array observed.

Algo :
left->right till increasing
right->left till decreasing
adjust min in subarray to left
adjust max in subarray to right
Notes :
Forgot testcase when no array is possible.
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left=0, right=nums.size()-1, minLeft=1000000, maxRight=-1000000;

        for(;left+1<nums.size();++left){
            if(nums[left]>nums[left+1])
                break;
        }

        for(;right-1>=0;--right){
            if(nums[right]<nums[right-1])
                break;
        }

        for(int i=left;i<=right;++i){
            if(minLeft>nums[i]) minLeft = nums[i];
            if(maxRight<nums[i]) maxRight = nums[i];
        }

        while(left-1>=0 && nums[left-1]>minLeft) --left;
        while(right+1<nums.size() && nums[right+1]<maxRight) ++right;

        if(right>left)
        return right-left+1;
        else
        return 0;
    }
};

int main(){
    vector<int> v;
    v.push_back(1 );
    v.push_back(2 );
    v.push_back(3 );
    v.push_back(4 );
    Solution *s = new Solution();
    cout<<s->findUnsortedSubarray(v);

}
