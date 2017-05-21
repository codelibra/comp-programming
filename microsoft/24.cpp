//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/write-a-c-program-to-find-the-parity-of-an-unsigned-integer/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int a,parity=0,b;
	cin>>a;
	b=a;
	while(a)
	{
		if(a&1)
		parity=!parity;
		a/=2;
	}
	cout<<parity<<endl;
	
	parity=0;
	while(b)
	{
		b&=(b-1);
		parity=!parity;
	}
	cout<<parity;
}
