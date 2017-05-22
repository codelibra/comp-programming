//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/position-of-rightmost-set-bit/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	cout<<(N&(-N));
	
	//-N is two's compliment of N
	//this is reversing all digits except rightmost 1!!
	//then anding with it
}
