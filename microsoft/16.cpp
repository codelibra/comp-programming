//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/check-for-majority-element-in-a-sorted-array/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[] = {1, 2, 3, 3, 3, 3, 10};
	int x,n=sizeof(arr)/sizeof(int);cin>>x;
	
	if(upper_bound(arr,arr+n,x)-lower_bound(arr,arr+n,x)>=n/2)
	cout<<"yes";
	else
	cout<<"no";
	
}
