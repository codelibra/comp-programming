//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,k,sum;
	cin>>N;
	int arr[100];
	for(int i=0;i<N;++i)
		cin>>arr[i];
	
	int jump[100];
	for(int i=0;i<N;++i)jump[i]=100000;
	
	jump[0]=0;
	for(int i=0;i<N;++i)
	{
		for(int j=i+1;j<=i+arr[i];++j)
		{
			if(jump[j]>jump[i]+1)
			jump[j]=jump[i]+1;
		}
	}
	cout<<jump[N-1]<<endl;
	
}
