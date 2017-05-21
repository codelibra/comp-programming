//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
//A-a is 32 hence inverting 6th bit will lead to chnge in case!
int main()
{
	string a,b;
	cin>>a>>b;
	int i;
	for(i=0;i<min(a.length(),b.length());++i)
	{
		if(a[i]==b[i] || (a[i]^32)==b[i])
		continue;
		else
		break;
	}
	
	if(a[i]==b[i])
	cout<<0;
	else if(a[i]<b[i])
	cout<<-1;
	else
	cout<<1;
	return 0;
}
