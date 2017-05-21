//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[100],N;
	cin>>N;
	for(int i=0;i<N+2;++i)cin>>arr[i];
	
	int xo=0,setbit,a=0,b=0;
	
	for(int i=0;i<N+2;++i)
	xo^=arr[i];
	for(int i=1;i<=N;++i)
	xo^=i;
	
	setbit=xo&(-xo);
	
	for(int i=0;i<N+2;++i)
	{
		if(setbit & arr[i])
		a^=arr[i];
		else
		b^=arr[i];
	}
	for(int i=1;i<=N;++i)
	{
		if(setbit & i)
		a^=i;
		else
		b^=i;
	}
	cout<<a<<" "<<b;
}
