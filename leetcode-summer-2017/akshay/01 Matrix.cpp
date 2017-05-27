#include<vector>
using namespace std;

class Solution {
public:
  vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int max = 30000;
        vector<vector<int> > distance(row+2, vector<int>(col+2,max));
        for(int i=0;i<row;i++)
        {
          for(int j=0;j<col;j++)
          {
            if(matrix[i][j]==0)
            {
              distance[i+1][j+1]=0;
            }
          }
        }

        bool done = false;
        for(int d=1; !done ; d++)
        {
          done = true;
          for(int i=1;i<=row;i++)
          {
            for(int j=1;j<=col;j++)
            {
              if(distance[i][j]>min(distance[i][j-1],min(distance[i][j+1],min(distance[i-1][j],distance[i+1][j])))+1)
              {
                distance[i][j] = min(distance[i][j-1],min(distance[i][j+1],min(distance[i-1][j],distance[i+1][j]))) + 1;
                done = false;
              }
            }
          }
        }

        vector<vector<int> > returned(row,vector<int>(col,max));
        for(int i=0;i<row;i++)
        {
          for(int j=0;j<col;j++)
          {
            returned[i][j] = distance[i+1][j+1];
          }
        }


        return returned;
  }

};
