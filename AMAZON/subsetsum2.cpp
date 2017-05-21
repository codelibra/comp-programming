//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;

void Generate(int arr[],int ans[],int N,int sz,int index,int sum,int target)
{
	if(index>N) return;
	if(sum==target)
	{
		for(int i=0;i<sz;++i)
		cout<<ans[i]<<" ";
		cout<<endl;
		
		Generate(arr,ans,N,sz-1,index+1,sum-ans[sz-1],target);
	}
	else
	{
		for(int i=index;i<N;++i)
		{
			if(arr[i]+sum<=target)
			{
				ans[sz]=arr[i];
				Generate(arr,ans,N,sz+1,i+1,sum+arr[i],target);
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
	Generate(arr,ans,N,0,0,0,target);
}
int main()
{
    int weights[] = {10, 5, 10, 15, 12, 20, 15};
    int target = 15;
    SubsetSum(weights,7,target);

}
