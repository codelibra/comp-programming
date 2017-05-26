#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {

        if(word1.empty())
          return word2.size();
        if(word2.empty())
          return word1.size();

        vector<vector<int> > matrix(word1.size(), vector<int>(word2.size(),0));

        if(word1[0] == word2[0])
          matrix[0][0] = 1;

        for(int j=1;j<word2.size();j++)
        {
          if(word1[0]==word2[j])
            matrix[0][j] = 1;
          else
            matrix[0][j] = matrix[0][j-1];
        }

        for(int i=1;i<word1.size();i++)
        {
          if(word1[i]==word2[0])
            matrix[i][0] = 1;
          else
            matrix[i][0] = matrix[i-1][0];
        }

        for(int i=1;i<word1.size();i++)
        {
          for(int j=1;j<word2.size();j++)
          {
            if(word1[i]==word2[j])
            {
              matrix[i][j] = matrix[i-1][j-1] + 1;
            }
            else
            {
              matrix[i][j] = max(matrix[i-1][j],max(matrix[i-1][j-1],matrix[i][j-1]));
            }
          }
        }
        return (word1.size() - matrix[word1.size()-1][word2.size()-1])  + (word2.size() - matrix[word1.size()-1][word2.size()-1]);
      }
};
