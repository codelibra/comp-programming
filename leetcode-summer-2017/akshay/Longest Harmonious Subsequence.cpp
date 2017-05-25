#include<iostream>
#include <map>
#include <vector>

using namespace std;

int findLHS(vector<int>& nums)
{
    if(nums.size()==0)
      return 0;
    map<int, int> num_count_map;
    for(int i=0; i<nums.size(); i++)
    {
      num_count_map[nums[i]] = num_count_map[nums[i]] +1;
    }

    int max_length=0;
    int current_length=0;
    for(map<int, int>::iterator i=num_count_map.begin(), j = --num_count_map.end(); i!=j; ++i)
    {
      map<int, int>::iterator i_next = i;
      i_next++;
      if((i_next->first - i->first)==1)
      {
        current_length = i->second + i_next->second;
        if(max_length<current_length)
          max_length = current_length;
      }
    }
    return max_length;
}
