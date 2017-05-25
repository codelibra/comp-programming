/**
Coding is addictive!!

URL : https://leetcode.com/problems/brick-wall/#/description
Test cases :
Algo :
Notes :
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int> >& wall) {
        set<int> uniqueCracks;
        int minCracks = wall.size();

        for(int i=0;i<wall.size();++i){
            int sum = 0;
            for(int j=0;j<wall[i].size();++j){
                sum = sum + wall[i][j];
                wall[i][j] = sum;
                uniqueCracks.insert(wall[i][j]);
            }
        }

        set<int>::iterator it;

        for(it=uniqueCracks.begin();it!=uniqueCracks.end();++it){
            int cracks = 0;
            for(int i=0;i<wall.size();++i){
                if(!binary_search (wall[i].begin(), wall[i].end(), *it)){
                    cracks = cracks + 1;
                }
            }
            if(cracks<minCracks){
                minCracks = cracks;
            }
        }

        return minCracks;

    }
};

int main(){
    Solution *s = new Solution();
//b    cout<<s->
}
