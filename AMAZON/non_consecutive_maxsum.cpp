//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;

int maxsum(int arr[],int N)
{
	int incl=0,excl=0;
	bool present=0;
	
	for(int i=0;i<N;++i)
	if(arr[i]>0) present=1;
	
	if(!present) return *max_element(arr,arr+N);
	for(int i=0;i<N;++i)
	{
		if(arr[i]>0)
		{
			int temp=max(incl,excl);
			incl=excl+arr[i];
			excl=temp;
		}
		else
		excl=max(incl,excl);
	}
	
	return max(incl,excl);
}

int main()
{
	int arr[]={3 ,-2 ,1 ,-10};
	
	cout<<maxsum(arr,4);
}
