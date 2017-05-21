//shivi..coding is adictive!!
//Equilibrium index of an array
#include<shiviheaders.h>
using namespace std;
int leftsum[100],rightsum[100];
int main()
{
	int arr[] = {-7, 1, 5, 2, -4, 3, 0};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	leftsum[0]=arr[0];
	for(int i=0;i<arr_size;++i)leftsum[i]=leftsum[i-1]+arr[i];
	
	rightsum[arr_size-1]=arr[arr_size-1];
	for(int i=arr_size-2;i>=0;--i)rightsum[i]=rightsum[i+1]+arr[i];
	
	for(int i=0;i<arr_size;++i)
	cout<<leftsum[i]<<" ";
	cout<<endl;
	for(int i=0;i<arr_size;++i)
	cout<<rightsum[i]<<" ";
	cout<<endl;
	for(int i=0;i<arr_size;++i)
	{
		if(leftsum[i]==rightsum[i])
		{
			cout<<i+1<<endl;
			break;
		}
	}
}
