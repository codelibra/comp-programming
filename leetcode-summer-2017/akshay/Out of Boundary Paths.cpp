#include<vector>
using namespace std;

class Solution {
public:

    void copyVector(vector<vector<unsigned long int> >& dest, vector<vector<unsigned long int> >& src)
    {
        for(int i=0;i<src.size();i++)
        {
          for(int j=0;j<src[0].size();j++)
          {
            dest[i][j] = src[i][j];
          }
        }
    }

    int findPaths(int m, int n, int N, int p, int q) {
          vector<vector<unsigned long int> > current(m+2, vector<unsigned long int>(n+2,0));
          vector<vector<unsigned long int> > one(m+2, vector<unsigned long int>(n+2,0));
          const unsigned int M = 1000000007;

          if(N==0)
            return 0;

          one[1][1] = 2;
          one[m][1] = 2;
          one[1][n] = 2;
          one[m][n] = 2;

          for(int i=2;i<m;i++)
          {
            one[i][1] = 1;
          }
          for(int i=2;i<m;i++)
          {
            one[i][n] = 1;
          }

          if(n==1)
          {
             for(int i=1;i<=m;i++)
            {
                one[i][1] += 1;
            }
          }


          for(int j=2;j<n;j++)
          {
            one[1][j] = 1;
          }
          for(int j=2;j<n;j++)
          {
            one[m][j] = 1;
          }

          if(m==1)
          {
              for(int j=1;j<=n;j++)
              {
                  one[1][j] += 1;
              }
          }

          vector<vector<unsigned long int> > previous(one.begin(), one.end());

          for(int steps=2; steps<=N;steps++)
          {
            for(int i=1;i<=m;i++)
            {
              for(int j=1;j<=n;j++)
              {
                current[i][j] = (previous[i][j-1] + previous[i][j+1]+ previous[i-1][j]+ previous[i+1][j] + one[i][j])%M;
              }
            }
            copyVector(previous,current);
          }



          return previous[p+1][q+1];
    }
};
