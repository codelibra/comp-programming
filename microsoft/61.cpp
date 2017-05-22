//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/
#include<shiviheaders.h>
using namespace std;
int LIS[100];
int main()
{
	int N,k,sum;
	cin>>N;
	int arr[100];
	for(int i=0;i<N;++i)
		cin>>arr[i];
	
	LIS[0]=arr[0];
	
	for(int i=1;i<N;++i)
	{
		for(int j=0;j<i;++j)
		{
			if(arr[j]<arr[i] && LIS[i]<LIS[j]+arr[i])
			LIS[i]=LIS[j]+arr[i];
		}
	}
	
	cout<<*(max_element(LIS,LIS+N));
}
