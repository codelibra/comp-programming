/**
Coding is addictive!!

URL : https://leetcode.com/problems/kill-process/#/description
Test cases :
Algo :
recursive dfs.
performance improvement to avoid tle is to store children in a map.
Notes :
**/

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> killList;
        stack<int> unvisited;
        map<int, vector<int> > children;

        for(int i=0;i<ppid.size();++i){
            if(children.find(ppid[i])==children.end()) {
                vector<int> v;v.push_back(pid[i]);
                children[ppid[i]] = v;
            }
            else{
                vector<int> v=children[ppid[i]];
                v.push_back(pid[i]);
                children[ppid[i]] = v;
            }
        }

        unvisited.push(kill);

        while(!unvisited.empty()){
            int p = unvisited.top();
            unvisited.pop();
            killList.push_back(p);

            vector<int> c = children[p];
            for(int i=0;i<c.size();++i){
                unvisited.push(c[i]);
            }
        }

        return killList;
    }
};

int main(){
    Solution *s = new Solution();
    vector<int> a;a.push_back(1);a.push_back(3);a.push_back(10);a.push_back(5);
    vector<int> b;b.push_back(3);b.push_back(0);b.push_back(5);b.push_back(3);
    vector<int> v = s->killProcess(a,b,3);
    for(int i=0;i<v.size();++i)
    cout<<v[i]<<endl;
}
