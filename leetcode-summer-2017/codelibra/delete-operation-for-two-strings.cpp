/**
Coding is addictive!!

URL : https://leetcode.com/problems/delete-operation-for-two-strings/#/description
Test cases :
Algo :
Notes :
**/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    string removeIthCharaterFromString(string str, int i){
        str.erase(str.begin()+i);
        return str;
    }

    void findMinDistance(string word1, string word2, int &minDistance, int numSteps){
        if(word1.length()==0 || word2.length()==0) return;
        
        if(word1.compare(word2)==0){
            if(numSteps<minDistance) {
                cout<<word1<<" "<<word2<<endl;
                minDistance = numSteps;
            }
            return ;
        }

        for(int i=0;i<word1.length();++i){
            findMinDistance(removeIthCharaterFromString(word1,i), word2, minDistance, numSteps+1);
        }
        for(int i=0;i<word2.length();++i){
            findMinDistance(word1, removeIthCharaterFromString(word2,i), minDistance, numSteps+1);
        }
    }

    int minDistance(string word1, string word2) {
        int minDistance = word1.length() + word2.length();
        findMinDistance(word1, word2, minDistance, 0);
        return minDistance;
    }
};

int main(){
    Solution *s = new Solution();
    cout<<s->minDistance("spartan","part");
}
