//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/leaders-in-an-array/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[] = {16, 17, 4, 3, 5, 2},n=sizeof(arr)/sizeof(int);
	int maxi=arr[n-1];
	for(int i=n-2;i>=0;--i)
	{
		if(arr[i]>maxi)
		maxi=arr[i];
	}
	cout<<maxi;
}
