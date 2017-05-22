//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/find-whether-a-given-number-is-a-power-of-4-or-not/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int n,count=0;
	cin>>n;
	
	while(n)
	{
		if(!(n&1))
		++count;
		n>>=1;
	}
	if((count&1)==0) cout<<"yes";
	else cout<<"No";
}
