#include<map>
#include<string>
using namespace std;

class Solution {
public:

  map<char,int> stringMap(string s)
  {
    map<char,int> result;
    for(int i=0;i<s.size();i++)
    {
      result[s[i]] = result[s[i]] + 1;
    }
    return result;
  }

    bool equalMap(map<char,int> s1Map, map<char,int> s2Map)
    {
      if(s1Map.size() != s2Map.size())
        return false;

      for(map<char,int>::iterator s1it = s1Map.begin(),s2it = s2Map.begin(); s1it!=s1Map.end() && s2it!= s2Map.end(); s1it++,s2it++)
      {
        if((s1it->first != s2it->first) || (s1it->second != s2it->second))
          return false;
      }
      return true;
    }

    bool checkInclusion(string s1, string s2)
    {
        if(s1.size()>s2.size())
          return false;

        map<char,int> s1Map = stringMap(s1);
        int length = s1.size();
        map<char,int> s2Map = stringMap(s2.substr(0,length));
        if(equalMap(s1Map,s2Map))
          return true;
        for(int i=1; i<s2.size()-s1.size()+1;i++)
        {
          s2Map[s2[i-1]] = s2Map[s2[i-1]] -1;
          if(s2Map[s2[i-1]] == 0)
            s2Map.erase(s2[i-1]);

          s2Map[s2[i+length-1]] = s2Map[s2[i+length-1]] + 1;

          if(equalMap(s1Map,s2Map))
            return true;
        }
        return false;
    }
};
