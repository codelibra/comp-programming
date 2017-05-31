#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        vector<int> numbers(n,0);
        vector<int> prevNumber(primes.size(),0);

        numbers[0]=1;
        for(int i=1;i<n;i++)
        {
            int min = INT_MAX;
            for(int j=0;j<primes.size();j++)
            {
              if(min>numbers[prevNumber[j]]*primes[j])
              {
                min = numbers[prevNumber[j]]*primes[j];
              }
            }
            numbers[i] = min;
            for(int j=0;j<primes.size();j++)
            {
                if(numbers[prevNumber[j]]*primes[j] == min)
                    prevNumber[j]++;
            }
        }

        return numbers[n-1];
    }
};
