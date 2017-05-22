//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/write-an-efficient-method-to-check-if-a-number-is-multiple-of-3/
#include<shiviheaders.h>
using namespace std;
int MultipleOfThree(int n)
{
	int odd=0,even=0;
	if(n<0) n=-n;
	if(n==0) return 1;
	if(n==1) return 0;
	
	while(n)
	{
		if(n&1)
		++odd;
		n=n>>1;
		
		if(n&1)
		++even;
		n=n>>1;
	}
	
	return MultipleOfThree(abs(odd-even));
}
int main()
{
	int a;
	cin>>a;
	cout<<MultipleOfThree(a);
}
