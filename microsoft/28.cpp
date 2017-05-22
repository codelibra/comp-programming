//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/
#include<shiviheaders.h>
using namespace std;
int arr[10000];
int main()
{
	int n,k=0,xr=0,a=0,b=0;
	cin>>n;
	for(int i=0;i<n;++i)cin>>arr[i];
	
	for(int i=0;i<n;++i)xr^=arr[i];
	
	xr=(xr&(-xr));
	
	for(int i=0;i<n;++i)
	{
		if(arr[i]&xr)
		a=a^arr[i];
		else
		b=b^arr[i];
	}
	cout<<a<<" "<<b<<endl;
}
