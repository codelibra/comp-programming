/**
Coding is addictive!!

URL : https://leetcode.com/problems/distribute-candies/#/description
Test cases :
Algo :
Notes :
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
     set<int> freq;
     for(int i=0;i<candies.size();++i){
         freq.insert(candies[i]);
     }

     int categories = freq.size(), len = candies.size()/2;
     return min(categories, len);
    }
};
int main(){
    Solution *s = new Solution();
    cout<<s->
}
