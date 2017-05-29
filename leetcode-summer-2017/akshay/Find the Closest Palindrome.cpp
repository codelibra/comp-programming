#include<string>
using namespace std;


class Solution {
public:
    string generatePalindrome(string s)
    {
      int last = s.size()-1;
      for(int i=0; i<s.size()/2; i++)
      {
        s[last - i] = s[i];
      }
      return s;
    }


    string nearestPalindromic(string n)
    {
        unsigned long int number = strtoul(n.c_str(),NULL,0);

        unsigned long int firstNumber = strtoul(generatePalindrome(n).c_str(),NULL,0);
        unsigned long int secondNumber = firstNumber;

        unsigned long int next = number;
        while(1)
        {
          if(firstNumber<number)
            next = number+1;
          else if(firstNumber>number)
            next = number-1;
          else
            return to_string(firstNumber);

          string second = generatePalindrome(to_string(next));
          secondNumber = strtoul(second.c_str(),NULL,0);
          if(firstNumber!=secondNumber)
                break;
        }
        if(abs(number-firstNumber) < abs(number-secondNumber))
          return to_string(firstNumber);
        else if(abs(number-firstNumber) > abs(number-secondNumber))
          return to_string(secondNumber);
        else
        {
            if(firstNumber>secondNumber) return to_string(secondNumber);
            else return to_string(firstNumber);
        }
    }
};
