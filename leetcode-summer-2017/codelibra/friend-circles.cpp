/**
Coding is addictive!!

URL : https://leetcode.com/problems/friend-circles/#/description
Test cases :
Algo :
number of connected components in a graph
Notes :
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int getNextNodeToVisit(vector<int> &visited){
            for(int i=0;i<visited.size();++i){
                if(visited[i]!=1) return i;
            }
            return -1;
    }

    void dfs(int node, vector<vector<int> >&adjacencyMatrix, vector<int> &visited){
        visited[node] = 1;

        vector<int> neighbours;
        for(int i=0;i<adjacencyMatrix[node].size();++i){
            if(adjacencyMatrix[node][i]==1 && i!=node){
                neighbours.push_back(i);
            }
        }

        for(int i=0;i<neighbours.size();++i){
            if(visited[neighbours[i]]!=1){
                dfs(neighbours[i], adjacencyMatrix, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int> >& M) {
        int connectedComponents = 0;
        vector<int> visited;
        for(int i=0;i<M.size();++i){
            visited.push_back(0);
        }

        while(getNextNodeToVisit(visited)!=-1){
            ++connectedComponents;
            int node = getNextNodeToVisit(visited);
            dfs(node, M, visited);
        }
        return connectedComponents;
    }
};

int main(){
    Solution *s = new Solution();

    vector<vector<int> > matrix;
    vector<int> a;a.push_back(1);a.push_back(1);a.push_back(0);
    vector<int> b;b.push_back(1);b.push_back(1);b.push_back(1);
    vector<int> c;c.push_back(0);c.push_back(1);c.push_back(1);
    matrix.push_back(a);matrix.push_back(b);matrix.push_back(c);

    cout<<s->findCircleNum(matrix);
}
