//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/next-power-of-2/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int a,n=1,b;
	cin>>a;
	b=a;
	
	if(a==1) {cout<<2;
	return 0;}
	while(n<a)
		n=n<<1;
	if(n==a)	n<<=1;
	cout<<n<<endl;	
	
	--b;
	b|=b>>1;
	b|=b>>2;
	b|=b>>4;
	b|=b>>8;
	b|=b>>16;
	
	cout<<b+1;
	
	
}
