//shivi..coding is adictive!!
//Find the repeating and the missing 
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int arr[100];
	for(int i=1;i<=N;++i)cin>>arr[i];
	
	for(int i=1;i<=N;++i)
	{
		if(arr[abs(arr[i])]>0)
		arr[abs(arr[i])]=-arr[abs(arr[i])];
		else
		cout<<abs(arr[i])<<endl;
	}
	for(int i=1;i<=N;++i)
	{
		if(arr[i]>0)
		cout<<i<<endl;
	}
	
	int set_bit,a=0,b=0,xo=0;
	for(int i=1;i<=N;++i)
	{
		xo^=abs(arr[i]);
	}
	for(int i=1;i<=N;++i)
	{
		xo^=i;
	}
	
	set_bit=xo&(-xo);
	
	for(int i=1;i<=N;++i)
	{
		if(abs(arr[i])&set_bit)
		a^=abs(arr[i]);
		else
		b^=abs(arr[i]);
	}
	for(int i=1;i<=N;++i)
	{
		if(i&set_bit)
		a^=i;
		else
		b^=i;
	}
	cout<<a<<' '<<b<<endl;
	
	
	
}
