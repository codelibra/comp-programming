//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/compute-modulus-division-by-a-power-of-2-number/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int a,d;
	cin>>a>>d;
	cout<<a-(a&(-a));
}
