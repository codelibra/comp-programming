//shivi..coding is adictive!!
//maximu repeating elemnt in O(n) time & O(1) space
#include<shiviheaders.h>
using namespace std;
int arr[10000];
int main()
{
	int N,k;
	cin>>N>>k;
	for(int i=0;i<N;++i) cin>>arr[i];
	
	for(int i=0;i<N;++i)
		arr[arr[i]%k]+=k;
	
	int maxval=0,temp=arr[0];
	
	for(int i=1;i<N;++i)	
	{
		if(arr[i]>temp)
		{
			maxval=i;
			temp=arr[i];
		}
	}
	cout<<maxval;
	
	//restore
	
	for(int i=0;i<N;++i)
	arr[i]%=k;
}

