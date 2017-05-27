#include <utility>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    int time_diff1(pair<int,int>& p1, pair<int,int>&p2)
    {
      return time_diff1(p1.second,p1.first,p2.second,p2.first);
    }

    int time_diff1(int min1, int hr1, int min2, int hr2)
    {
      int min_diff = 60-min1;
      int hr_diff = hr2 - (hr1+1);
      min_diff += min2;

      return min_diff + 60*(hr_diff);
    }

    int time_diff2(pair<int,int>& p1, pair<int,int>&p2)
    {
      return time_diff2(p1.second,p1.first,p2.second,p2.first);
    }

    int time_diff2(int min1, int hr1, int min2, int hr2)
    {
      int min_diff = 60-min1;
      int hr_diff = 24 - (hr1+1);
      hr_diff += hr2;
      min_diff += min2;

      return min_diff + 60*(hr_diff);
    }

    void sortPairs(vector<pair<int,int> >& v)
    {
      sort(v.begin(),v.end());
    }

    pair<int,int> buildPair(string s)
    {
      pair<int,int> p;
      int hr = atoi(s.substr(0,2).c_str());
      int min = atoi(s.substr(3,2).c_str());
      p = make_pair(hr,min);
      return p;
    }

    int findMinDifference(vector<string>& timePoints)
    {
          vector<pair<int,int> > timeVector;
          for(int i=0;i<timePoints.size();i++)
          {
            timeVector.push_back(buildPair(timePoints[i]));
          }

          sortPairs(timeVector);

          int min = 90000;
          for(int i=0;i<timeVector.size()-1;i++)
          {
            if(min>time_diff1(timeVector[i],timeVector[i+1]))
              min = time_diff1(timeVector[i],timeVector[i+1]);
          }

          if(min>time_diff2(timeVector[timeVector.size()-1],timeVector[0]))
            min=time_diff2(timeVector[timeVector.size()-1],timeVector[0]);

        return min;
    }
};
