//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/find-subarray-with-given-sum/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,k,sum;
	cin>>N;
	int arr[100];
	for(int i=0;i<N;++i)
		cin>>arr[i];
		
	cin>>sum;
	
	int curr_sum=arr[0],start=0,i=0;
	
	while(start<N)
	{
		while(curr_sum>sum && start<N)
		{
			curr_sum=curr_sum-arr[start];
			++start;
		}
		
		if(curr_sum==sum)
		{
			cout<<"found";
			break;
		}
		
		else
		curr_sum+=arr[i++];
	}
	
}
