//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/maximum-difference-between-two-elements/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,arr[100];
	cin>>N;
	for(int i=0;i<N;++i)cin>>arr[i];
	
	int min_so_far=arr[0],mindiff=INT_MIN;
	for(int i=1;i<N;++i)
	{
		if(arr[i]-min_so_far> mindiff)
		mindiff=arr[i]-min_so_far;
		
		if(min_so_far>arr[i])
		min_so_far=arr[i];
	}
	
	cout<<mindiff;
}
