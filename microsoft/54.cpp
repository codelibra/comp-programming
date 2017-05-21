//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,k,sum;
	cin>>N;
	int arr[100];
	for(int i=0;i<N;++i)cin>>arr[i];
	
	cin>>sum;
	sort(arr,arr+N);
	for(int i=0;i<N;++i)
	{
		for(int j=i+1;j<N;++j)
		{
			int l=j+1;
			int r=N-1;
			while(l<r)
			{
				if(arr[l]+arr[r]+arr[i]+arr[j]==sum)
				{
					cout<<arr[l]<<" "<<arr[r]<<" "<<arr[i]<<" "<<arr[j]<<endl;
					break;
				}
				else if(arr[l]+arr[r]+arr[i]+arr[j]>sum)
					--r;
				else if(arr[l]+arr[r]+arr[i]+arr[j]<sum)
					++l;	
			}
		}
	}
	
	
}
