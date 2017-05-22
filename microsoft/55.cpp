//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/
#include<shiviheaders.h>
using namespace std;
int arr[100];

bool isSubsetSum(int N,int sum)
{
	if(sum==0)
	return true;
	
	if(N==0 && sum!=0)
	return false;
	
	if(arr[N-1]>sum)
	return isSubsetSum(N-1,sum);
	
	else
	return isSubsetSum(N-1,sum)|isSubsetSum(N-1,sum-arr[N-1]);
}

int main()
{
	int N,k,sum=0;
	cin>>N;
	for(int i=0;i<N;++i){cin>>arr[i];sum+=arr[i];}
	
	if(sum%2!=0)
	cout<<"Not possible";
	else if(isSubsetSum(N,sum/2))
	cout<<"possible";
	
	
}
