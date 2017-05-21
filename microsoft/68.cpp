//shivi..coding is adictive!!
//set bits from 1 to n
#include<shiviheaders.h>
using namespace std;

int setbits(int n)
{
	int count=0;
	while(n)
	{
		if(n&1)
		++count;
		n>>=1;
	}
	return count;
}


int setbits2(int n)
{
	int count=0;
	while(n)
	{
		n&=n-1;
		++count;
	}
	return count;
}


int main()
{
	int n,count=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	count+=setbits2(i);
	
	cout<<count;
}
