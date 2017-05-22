//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
#include<shiviheaders.h>
using namespace std;
int hash[100];
int main()
{
	int N,k,sum;
	cin>>N;
	int arr[100];
	for(int i=0;i<N;++i)
	{
		cin>>arr[i];
		if(arr[i]==0) arr[i]=-1;
	}
	for(int i=1;i<N;++i) arr[i]=arr[i-1]+arr[i];
	
	int maxi=*max_element(arr,arr+N),maxdiff=INT_MIN;
	
	for(int i=0;i<N;++i)
	{
		if(hash[arr[i]]==0)
		{
			hash[arr[i]]=i;
		}
		else
		{
			if(i-hash[arr[i]]>maxdiff)
			maxdiff=i-hash[arr[i]];
		}
	}
	
	cout<<maxdiff<<endl;
	
	
	
}
