//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/#comment-9236
#include<shiviheaders.h>
using namespace std;
int getSetBitsFromOneToN(int N)
{
    int two = 2,ans = 0;
    int n = N;
    while(n)
    {
        ans += (N/two)*(two>>1);
        
        if((N&(two-1)) > (two>>1)-1) ans += (N&(two-1)) - (two>>1)+1;
        
        two <<= 1;
        
        n >>= 1;
    }
    return ans;
}
int main()
{
	
}

/*
Consider the ith least significant bit(1 based indexing) for numbers from 1 to N , then they repeat with a period equal to 2^i.
And in the period , first half of the values are 0 and the next half are ones.
For example :-
For numbers from 0 to 7,(0 will contribute nothing so no effect)
000
001
010
011
100
101
110
111
1st least significant bit = 01010101 Period=2
2nd least significant bit = 00110011 Period=4
3rd least significant bit = 00001111 Period=8
and so on.
So for the ith least significant bit ,answer will be (N/Period)*(Half of Period Size) + (N%Remainder - Half of Period Size)
The second term will only be taken when N%Remainder is greater than or equal to Half of Period Size.
Also , N%(2^i) can be written as N&(2^i - 1)

*/
