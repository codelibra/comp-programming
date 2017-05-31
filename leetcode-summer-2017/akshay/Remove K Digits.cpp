#include<vector>
#include<string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int getNumber(int i, int j, string num)
    {
        return atoi(num.substr(i,j-i+1).c_str());
    }

    string removeKdigits(string num, int removeNumbers)
    {
      int c = num.size() - removeNumbers;
      vector<vector<int> > f(num.size()+1,vector<int>(c+1,0));

      for(int i=0;i<num.size();i++)
      {
        for(int k=i;k<=c;k++)
        {
          f[i][k] = getNumber(0,i,num);
        }
      }

      for(int k=0;k<=c;k++)
        f[0][k] = 90000;

      for(int k=1;k<=c;k++)
      {
        for(int i=1;i<=num.size();i++)
        {
            f[i][k] = min(f[i-1][k],f[i-1][k-1]*10+getNumber(i,i,num));
        }
      }

      return to_string(f[num.size()][c]);
    }
};
