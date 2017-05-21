//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[]={10, 21, 22, 100, 101, 200, 300};
	sort(arr,arr+7);
	int N=7,count=0,k;
	
	for(int i=0;i<N;++i)
	{
		k=i+2;
		for(int j=i+1;j<N;++j)
		{
			while(k<N && arr[i]+arr[j]>arr[k]) ++k;
			count+=k-j-1;
		}
	}
	
	cout<<count<<endl;
}
