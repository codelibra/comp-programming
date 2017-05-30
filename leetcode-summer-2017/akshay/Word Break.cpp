#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   bool isPresent(int i,int k,string s,vector<vector<int> >& present,vector<string>& wordDict)
   {
     if(i>k)
      return true;

    if(find(wordDict.begin(),wordDict.end(),s.substr(i,k-i+1))!=wordDict.end())
      return true;

    if(present[i][k]==1)
      return true;

    return false;
   }

    bool wordBreak(string s, vector<string>& wordDict)
    {
      vector<vector<int> >present(s.size(),vector<int>(s.size(),0));

      for(int l=0;l<s.size();l++)
      {
        for(int i=0;i<s.size();i++)
        {
          int j=i+l;
          if(j<s.size())
          {
            for(int k=i; k<=j;k++)
            {
              if(isPresent(i,k,s,present,wordDict) && isPresent(k+1,j,s,present,wordDict))
              {
                present[i][j]=1;
                break;
              }
            }
          }
        }
      }

      return present[0][s.size()-1];
    }
};
