#include<vector>
#include<string>
#include <sstream>
#include<iostream>
using namespace std;

class Solution {
public:
   bool isValidTree(int i,int j, vector<string>& s,vector<vector<int> >& valid)
   {
      if(i>j) return false;
      if(valid[i][j]!=-1) return valid[i][j];

      if(i==j && s[i].compare("#")==0)
      {
        valid[i][j] = 1;
        return true;
      }

      if(i==j && s[i].compare("#")!=0)
      {
        valid[i][j] = 0;
        return false;
      }

      if(s[i].compare("#")==0)
      {
        valid[i][j] = 0;
        return false;
      }

      for(int k=i+1; k<=j; k++)
      {
        if(isValidTree(i+1,k,s,valid) && isValidTree(k+1,j,s,valid))
        {
          valid[i][j] = 1;
          return true;
        }
      }

      valid[i][j]=0;
      return false;
  }

    bool isValidSerialization(string p) {
        vector<string> preorder;
        istringstream ss(p);
        string token;
        while(getline(ss, token, ',')) {
            preorder.push_back(token);
        }

        vector<vector<int> > valid(preorder.size(), vector<int>(preorder.size(),-1));
        bool b = isValidTree(0,preorder.size()-1,preorder,valid);
        return b;
    }
};
