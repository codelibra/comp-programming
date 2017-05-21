//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,k;
	cin>>N;
	int arr[100];
	for(int i=0;i<N;++i)cin>>arr[i];
	
	int left=0,right=N-1;
	
	for(int i=0;i<N;++i)
		if(arr[i+1]<arr[i])
		{
			left=i+1;
			break;
		}
	for(int i=N-1;i>=0;--i)	
		if(arr[i-1]>arr[i])
		{
			right=i;
			break;
		}
	
	int maxi=*max_element(arr+left,arr+right);
	int mini=*min_element(arr+left,arr+right);
	
	while(arr[left-1]>mini)--left;
	while(arr[right+1]<maxi)++right;
	
	cout<<arr[left]<<' '<<arr[right]<<endl;
}
