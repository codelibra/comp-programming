#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
      map<int,vector<int> > processMap;

      for(int i=0;i<ppid.size();i++)
      {
          if(ppid[i]==0)
            continue;
          processMap[ppid[i]].push_back(pid[i]);
      }

      return killPid(kill,processMap);
    }

    vector<int> killPid(int kill,map<int,vector<int> >& processMap)
    {
      vector<int> killList;
      killList.push_back(kill);
      vector<int> childrenPid = processMap[kill];
      for(int i=0;i<childrenPid.size();i++)
      {
        vector<int> childKillList = killPid(childrenPid[i],processMap);
        killList.insert(killList.end(),childKillList.begin(),childKillList.end());
      }
      return killList;
    }
};
