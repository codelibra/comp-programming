//shivi..coding is adictive!!
//Find duplicates in O(n) time and O(1) extra space 
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[100],N;
	cin>>N;
	for(int i=0;i<N;++i)cin>>arr[i];
	
	for(int i=0;i<N;++i)
	{
		if(arr[abs(arr[i])]>0)
		arr[abs(arr[i])]=-arr[abs(arr[i])];
		else
		cout<<abs(arr[i])<<endl;
	}
}
