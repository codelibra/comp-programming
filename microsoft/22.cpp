//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/write-one-line-c-function-to-find-whether-a-no-is-power-of-two/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	cout<<(a&& (!(a&(a-1))));
}
