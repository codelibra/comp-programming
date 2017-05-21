//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int arr[100],N;
	cin>>N;
	for(int i=1;i<=N+2;++i)cin>>arr[i];
	
	for(int i=1;i<=N+2;++i)
	{
		if(arr[abs(arr[i])]>0)
		arr[abs(arr[i])]*=-1;
		
		else
		cout<<abs(arr[i])<<endl;
	}
}
