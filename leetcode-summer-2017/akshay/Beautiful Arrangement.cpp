using namespace std;

class Solution {
public:
    int compatible(int i, int j, int start, score)
    {
      if(i>j) return 1;
      if(score[i][j][start]!=-1) return score[i][j][start];

      if(j==i)
      {
        if(j%start==0 || start%j==0)
        {
          score[i][j][start]=1;
          return 1;
        }
        else
        {
          score[i][j][start]=0;
          return 0;
        }
      }

      for(int k=start;k<=j;k++)
      {
        compatible(k,k,i)
      }
    }
    int countArrangement(int N) {
        vector<vector<vector<int> > > score(N+1,vector<vector<int> >(N+1, vector<int>(N+1,-1)));

        score[1][N][1]
    }
};
