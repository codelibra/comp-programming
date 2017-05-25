/**
Coding is addictive!!

URL : https://leetcode.com/problems/next-greater-element-iii/#/description
Test cases :
Algo :
Notes :
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while(n>0){
            int digit = n%10;
            digits.push_back(digit);
            n= n/10;
        }
        reverse(digits.begin(), digits.end());

        int i = digits.size()-1, temp;
        while(i-1>=0){
            if(digits[i]<=digits[i-1]){
                --i;
            }
            else{
                break;
            }
        }

        if(i==0){
            return -1;
        }

        int j = digits.size()-1;
        while(j>=0){
            if(digits[j]<=digits[i-1]){
                --j;
            }
            else{
                break;
            }
        }

        temp = digits[i-1];
        digits[i-1] = digits[j];
        digits[j] = temp;


        sort(digits.begin()+i, digits.end());
        long k = 0;
        string str = "";
        for(int i=0;i<digits.size();++i){
            k = k * 10;
            k = k + digits[i];
            if(k>=INT_MAX) return -1;
        }
        return k;
    }
};

int main(){
    Solution *s = new Solution();
    cout<<s->nextGreaterElement(12);
}
