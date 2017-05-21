//shivi..coding is adictive!!
//Dynamic Programming | Set 7 (Coin Change)
#include<shiviheaders.h>
using namespace std;
int main()
{
	int donimations[]={1,2,3,4};
	int sum=40;
	int arr[41];
	arr[0]=0;
	for(int i=1;i<=40;++i)arr[i]=100000;
	
	for(int i=1;i<=40;++i)
	{
		for(int j=0;j<4;++j)
		{
			if(donimations[j]<=i)
			arr[i]=min(arr[i-donimations[j]]+1,arr[i]);
		}
	}
	cout<<arr[40]<<endl;
	
	for(int i=1;i<=40;++i)
	cout<<arr[i]<<" ";
}
