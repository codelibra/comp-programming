//shivi..coding is adictive!!
//Find the element that appears once
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[1000];
	int N;
	cin>>N;
	for(int i=0;i<N;++i)cin>>arr[i];
	
	int ans=0,x=1;
	
	for(int i=0;i<32;++i)
	{
		int sum=0;
		x=(1<<i);

		for(int j=0;j<N;++j)
		{
			if(arr[j]&x)
			++sum;
		}
		
		if(sum%3)
		ans|=x;
	}
	
	cout<<ans;
}
