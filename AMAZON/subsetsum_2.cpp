//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;

void Subset(int arr[],int ans[],int N,int sz,int i,int sum,int target)
{
	if(i>N) return;
	
	if(sum==target)
	{
		for(int p=0;p<sz;++p)
		cout<<ans[p]<<" ";
		cout<<endl;
		Subset(arr,ans,N,sz-1,i+1,sum-ans[sz-1],target);
	}
	
	else
	{
		for(int k=i;k<N;++k)
		{
			if(sum+arr[k]<=target)
			{	
				ans[sz]=arr[k];
				Subset(arr,ans,N,sz+1,k+1,sum+arr[k],target);
			}
			else
			break;
		}
	}
}

void SubsetSum(int arr[],int N,int target)
{
	int *ans=new int[N];
	sort(arr,arr+N);
	Subset(arr,ans,N,0,0,0,target);
}
int main()
{
	int weights[] = {10, 5, 10, 15, 12, 20, 15};
    int target = 15;
    SubsetSum(weights,7,target);
 
}
