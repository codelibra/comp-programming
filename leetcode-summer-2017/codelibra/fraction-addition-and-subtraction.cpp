/**
Coding is addictive!!

URL : https://leetcode.com/problems/fraction-addition-and-subtraction/#/description
Test cases :
check for numbers starting from -ve number
check for no addition or substraction just a single fraction
check for 0 numertor to return 0/1

Algo :
only tricky part is at the end divide num and deno by gcd.
Notes :
Miseed reading properly again!! The numbers can be more than 1 character long.
**/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int gcd(int a, int b){
        if (a == 0)
            return b;
        return gcd(b%a, a);
    }

    int getNextNumber(string expression, int &i){
        int num = 0;
        while(i<expression.length() && (expression[i]>='0' && expression[i]<='9')){
            num *=10;
            num = num + expression[i]-'0';
            ++i;
        }
        return num;
    }

    string fractionAddition(string expression) {
        int numerator[100000], denominator[100000];
        int productAllDeno = 1, valueAllNumo=0;
        int i=0,j=0;

        while(i<expression.length()){
            if(i==0 && (expression[i]!='+' && expression[i]!='-')){
                numerator[j] = getNextNumber(expression,i);++i;
                denominator[j] = getNextNumber(expression,i);
            }
            else{
                char op = expression[i];i=i+1;
                numerator[j] = getNextNumber(expression,i);++i;
                denominator[j] = getNextNumber(expression,i);
                if(op=='-') numerator[j] = numerator[j] * -1;
            }
            productAllDeno *= denominator[j];
            j = j + 1;
        }


        for(int i=0;i<j;++i){
            numerator[i] = (productAllDeno/denominator[i])*numerator[i];
            valueAllNumo += numerator[i];
        }

        if (valueAllNumo==0) return "0/1";
        else{
            int greatedCommonDivisor = gcd(abs(valueAllNumo), abs(productAllDeno));
            valueAllNumo /= greatedCommonDivisor;
            productAllDeno /= greatedCommonDivisor;
            return to_string(valueAllNumo) + "/" + to_string(productAllDeno);
        }
    }
};

int main(){
    Solution *s = new Solution();
    cout<<s->fractionAddition("3/10-1/15");
}
