/**
Coding is addictive!!

URL : https://leetcode.com/problems/permutation-in-string/#/description
Test cases :
Algo :
match the count array of both the strings.
both strings with length equal to the smaller string.
Notes :
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        int original[10000]={0}, parent[10000]={0}, start=0, end=s1.length()-1;
        bool matched = true;

        for(int i=0;i<s1.length();++i){
            original[int(s1[i])]++;
        }
        for(int i=start;i<=end;++i){
            parent[int(s2[i])]++;
        }

        for(int i=0;i<10000;++i){
            if(original[i]!=parent[i]){
                matched = false;
            }
        }
        if (matched){
            return true;
        }


        while(end+1<s2.length()){
            parent[int(s2[start])]--;
            ++start;
            ++end;
            parent[int(s2[end])]++;
            matched = true;

            for(int i=0;i<10000;++i){
                if(original[i]!=parent[i]){
                    matched = false;
                }
            }
            if (matched){
                return true;
            }
        }

        return false;
    }
};

int main(){
    Solution *s = new Solution();
    cout<<s->checkInclusion("ab","eidboaoo");
}
