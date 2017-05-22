//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int NO_OF_BITS=sizeof(a)*8,reversenum=0;
	
	for(int i=0;i<NO_OF_BITS;++i)
	{
		if(a&(1<<i))
		reversenum|=1<<(NO_OF_BITS-i-1);
	}
	cout<<reversenum<<endl;
}
