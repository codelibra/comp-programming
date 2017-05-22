//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int arr[100],N,k;
int kadane()
{
	int max_till_nw=INT_MIN,max_so_far=-100000;
	
	for(int i=0;i<N;++i)
	{
		max_so_far=max_so_far+arr[i];
		if(max_so_far<arr[i])
		max_so_far=arr[i];
		
		if(max_till_nw<max_so_far)
		max_till_nw=max_so_far;
	}
	return max_till_nw;
}

int minkadane()
{
	int min_till_nw=INT_MAX,min_so_far=arr[0];
	
	for(int i=1;i<N;++i)
	{
		min_so_far=min_so_far+arr[i];
		if(min_so_far>arr[i])
		min_so_far=arr[i];
		
		if(min_till_nw>min_so_far)
		min_till_nw=min_so_far;
	}
	return min_till_nw;
}

int main()
{
	int i;
	cin>>N;
	for(int i=0;i<N;++i)cin>>arr[i];
	
	int maxkadane=kadane(),sum=0,maxcircularkadane;
	
	for(int i=0;i<N;++i)sum+=arr[i];
	
	maxcircularkadane=sum-minkadane();
	cout<<max(maxcircularkadane,maxkadane);
}
