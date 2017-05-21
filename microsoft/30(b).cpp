//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	
	int mask=N>>10;
	
	cout<<((N+mask)^mask);
	
}
