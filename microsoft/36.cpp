//shivi..coding is adictive!!
#include<shiviheaders.h>
//Add two numbers without using arithmetic operators
using namespace std;
int main()
{
	int a,b,bita,bitb,carry=0,ans=0,sum,count=0;
	cin>>a>>b;
	while(a || b)
	{
		bita=1&a;
		bitb=1&b;
		
		sum=bita^bitb^carry;
		carry=(bita&bitb)|(bitb&carry)|(carry&bita);
		
		ans=ans|(sum<<count);
		a>>=1;
		b>>=1;
		++count;
	}
	
	if(carry)
	ans=(ans)|(carry<<count);
	cout<<ans;
}
