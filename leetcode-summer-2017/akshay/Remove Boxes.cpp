#include<vector>
#include<map>
using namespace std;

//THIS IS MY HUMBLE ATTEMPT.. IT IS INCORRECT

class Solution {
public:
    int maximum;

    void reachMax(vector<int>& boxes)
    {
      map<int, int> continuous;
      map<int, int> index;
      for(int i=0;i<boxes.size();i++)
      {
        continuous[boxes[i]] = 1;
        index[boxes[i]] = -1;
      }

      for(int i=0;i<boxes.size();i++)
      {
        if(index[boxes[i]] != -1)
        {
          if(index[boxes[i]]!=i-1)
            continuous[boxes[i]] = 0;
          else
            index[boxes[i]] = i;
        }
        else
          index[boxes[i]] = i;
      }

      for(map<int, int>::iterator it = continuous.begin(); it!=continuous.end(); it++)
      {
        if(it->second == 1)
        {
          removeBox(boxes, index[it->first]);
        }
      }
    }

    void removeWithMaxGain(vector<int>& boxes)
    {
      vector<map<int, int> > leftCount;
      vector<map<int, int> > rightCount;

      for(int i=0;i<boxes.size();i++)
      {
        map<int, int> counts;
        for(int j=i-1; j>=0; j--)
        {
          counts[boxes[j]]++;
        }
        leftCount.push_back(counts);
      }

      for(int i=0;i<boxes.size();i++)
      {
        map<int, int> counts;
        for(int j=i+1; j<boxes.size(); j++)
        {
          counts[boxes[j]]++;
        }
        rightCount.push_back(counts);
      }

      int max_gain_index = -1;
      int max_gain = -1;
      for(int i=0; i<boxes.size(); i++)
      {
        int gain = 0;
        for(map<int, int>::iterator it = leftCount[i].begin(); it!=leftCount[i].end(); it++)
        {
          gain += it->second * rightCount[i][it->first];
        }

        if(gain>max_gain)
        {
          max_gain = gain;
          max_gain_index = i;
        }
      }

      removeBox(boxes, max_gain_index);
    }

    void removeBox(vector<int>& boxes, int index)
    {
      int k = 1;
      int start = index;
      int end = index;
      for(int i=index-1;i>=0;i--)
      {
        if(boxes[index] == boxes[i])
        {
          k++;
          start = i;
        }
        else
         break;
      }

      for(int j =index+1; k<boxes.size();j++)
      {
        if(boxes[index]==boxes[j])
        {
          k++;
          end = j;
        }
        else
          break;
      }
      boxes.erase(boxes.begin()+start, boxes.begin()+end+1);
      maximum += (k*k);
    }


    int removeBoxes(vector<int>& boxes)
    {
      maximum = 0;
      while(!boxes.empty())
      {
        reachMax(boxes);
        removeWithMaxGain(boxes);
      }
      return maximum;
    }
};
