//shivi..coding is adictive!!
//Find position of the only set bit
#include<shiviheaders.h>
using namespace std;
int N;
bool CheckPowerOfTwo()
{
	return (N&!(N&(N-1)));
}
int main()
{
	int N,count=0;
	cin>>N;
	
	cout<<log2(N)+1<<endl;
	
	while(N)
	{
		++count;
		N>>=1;
	}
	cout<<count<<endl;
	
}
