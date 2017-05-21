//shivi..coding is adictive!!
//Smallest of three integers without comparison operators
#include<shiviheaders.h>

bool min(int x,int y)
{
	if((x-y)>>sizeof(int))
	return 1;
	else
	return 0;
}

//use it for finding 3 numbers
//2's compliment method
using namespace std;
int main()
{
	cout<<min(2,3);
}
