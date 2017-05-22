//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/two-elements-whose-sum-is-closest-to-zero/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[] = {1, 60, -10, 70, -80, 85};
	int n=sizeof(arr)/sizeof(int),i,j,ans=INT_MAX;
	
	sort(arr,arr+n);
	i=0,j=n-1;
	while(i<j)
	{
		int sum=arr[i]+arr[j];
		if(sum>0)
		--j;
		else if(sum<0)
		++i;
		ans=min(abs(ans),abs(sum));
	}
	cout<<ans;
}
