//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/segregate-even-and-odd-numbers/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,arr[100];
	cin>>N;
	for(int i=0;i<N;++i)
	cin>>arr[i];
	
	int i=0,j=N-1;
	while(i<j)
	{
		if(arr[i]%2!=0)
		{
		swap(arr[i],arr[j]);
		--j;
		}
		else
		++i;
	}
	for(int i=0;i<N;++i)
	cout<<arr[i]<<" ";
}
