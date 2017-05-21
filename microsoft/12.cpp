//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[] = {5,  5, 10, 40, 50, 35};
	int incl=arr[0],excl=0,exnew;
	
	for(int i=1;i<sizeof(arr)/sizeof(int);++i)
	{
		exnew=max(excl,incl);
		incl=excl+arr[i];
		excl=exnew;
	}
	
	cout<< max(incl,excl);
}
