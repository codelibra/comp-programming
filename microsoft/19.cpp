//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/count-set-bits-in-an-integer/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	
	b=a;
	
	//brain algo
	int count=0;
	while(a)
	{
		a&=a-1;
		++count;
	}
	cout<<count<<endl;
	count=0;
	while(b)
	{
		if(b&1)++count;
		b/=2;
	}
	cout<<count;
}
