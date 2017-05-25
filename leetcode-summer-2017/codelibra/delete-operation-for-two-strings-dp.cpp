/**
Coding is addictive!!

URL :
Test cases :
Algo :
This took a lottt of time to figure.. although a very easy dp problem.
Approach which came into my mind was initially...
take ANY substring of length=1 and compare
take ANY substring of length=2 and compare
and use above two as subproblems for solving the same.

But that was wrong, since the best of length=k can happen at any positions in both strings
which CANNOT be combined to solve bigger subproblem.

So catch here is.. we are taking substring starting at 0.
Using this.. we can always know which substring is in question given only length of substring.
This subproblem can be easily combined on the last matching character and answer of smaller subproblem.
Notes :
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(), m = word2.length();
        // dp of i,j represents i length of string 1 compared to j length of string 2
        int dp[n+1][m+1];

        for(int i=0;i<=n;++i){
            for(int j=0;j<=m;++j){
                if(i==0) dp[i][j] = j;
                else if(j==0) dp[i][j] = i;
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1]+2, min(dp[i-1][j]+1, dp[i][j-1]+1));
                }
            }
        }
        return dp[n][m];
    }
};

int main(){
    Solution *s = new Solution();
    cout<<s->minDistance("sea","eat");
}
