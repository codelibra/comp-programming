//shivi..coding is adictive!!
//add 1 to a number
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,K;
	cin>>N;
	K=N;
	//flip all bits before the first 0
	
	int m=1;
	while((N&m))
	{
		N^=m;
		m<<=1;
	}
	
	N=N|m;
	cout<<N<<endl;
	
	cout<<(-(~N));
}
