#include<vector>
using namespace std;

class Solution {
public:
  int nthUglyNumber(int n)
  {
    vector<unsigned long int> result;
    unsigned long int pow_2=1;
    for(int i=0;i<=30;i++)
    {
      unsigned long int pow_3=1;
        for(int j=0;j<=20;j++)
        {
          unsigned long int pow_5=1;
          for(int k=0;k<=15;k++)
          {
            unsigned long int num = pow_2*pow_3*pow_5;
            result.push_back(num);
            pow_5 = pow_5*5;
          }
          pow_3 = pow_3 *3;
        }
        pow_2 = pow_2 *2;
    }
    sort(result.begin(),result.end());

    return result[n-1];
  }
};
