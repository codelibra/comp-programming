/**
Coding is addictive!!

URL : https://leetcode.com/problems/valid-square/#/description
Test cases : nothing particular as such
Algo :
add all distances to a set, set should contain only diagonal and side
check diagonal square = 2 * side square
Notes :
rather than returning actual distance returning square of distance helped to keep things to precise integers.
just checking diagonal is twice side + all sides equal is sufficient conditions for square.
**/

#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

class Solution {
public:
    int distanceSq(int a, int b, int c, int d){
        return (a-c)*(a-c) + (b-d)*(b-d);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> allDistances;
        allDistances.insert(distanceSq(p1[0],p1[1],p2[0],p2[1]));
        allDistances.insert(distanceSq(p1[0],p1[1],p3[0],p3[1]));
        allDistances.insert(distanceSq(p1[0],p1[1],p4[0],p4[1]));
        allDistances.insert(distanceSq(p2[0],p2[1],p3[0],p3[1]));
        allDistances.insert(distanceSq(p2[0],p2[1],p4[0],p4[1]));
        allDistances.insert(distanceSq(p3[0],p3[1],p4[0],p4[1]));

        if(allDistances.size()!=2) return false;

        int side = *allDistances.begin(), diagonal = *allDistances.rbegin();
        if(2*side!=diagonal) return false;
        return true;
    }
};

int main(){
    Solution *s = new Solution();
    vector<int> a;a.push_back(0);a.push_back(0);
    vector<int> b;b.push_back(0);b.push_back(1);
    vector<int> c;c.push_back(1);c.push_back(0);
    vector<int> d;d.push_back(1);d.push_back(1);

    cout<<s->validSquare(a,b,c,d);
}
