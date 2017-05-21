//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/maximum-product-subarray/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,k,sum;
	cin>>N;
	int arr[100];
	for(int i=0;i<N;++i)
		cin>>arr[i];
		
	int max_so_far=INT_MIN,max_ending_here=1,min_ending_here=1;
	
	for(int i=0;i<N;++i)	
	{
		if(arr[i]>0)
		{
			max_ending_here=max_ending_here*arr[i];
			min_ending_here=min(min_ending_here*arr[i],1);
		}
		
		if(arr[i]==0)
		{
			max_ending_here=1;
			min_ending_here=1;
		}
		
		else
		{
			int temp=max_ending_here;
			max_ending_here=max(min_ending_here*arr[i],1);
			min_ending_here=temp*arr[i];
		}
		
		if(max_so_far<max_ending_here)
		max_so_far=max_ending_here;
	}
	cout<<max_ending_here<<endl;
	
}
