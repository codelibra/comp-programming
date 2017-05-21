//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/count-number-of-bits-to-be-flipped-to-convert-a-to-b/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int a,b,c,k,sum=0,d;
	cin>>a>>b;
	c=a^b;
	d=c;
	
	//brian kernighan's algorithm 
	while(c)
	{
		c&=c-1;
		++sum;
	}
	cout<<sum;
	sum=0;
	
	//normal algorithm
	c=d;
	while(c)
	{
		if(c&1)++sum;
		
		c>>=1;
	}
	cout<<sum;
}
