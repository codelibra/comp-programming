//shivi..coding is adictive!!
//String matching where one string contains wildcard characters
#include<shiviheaders.h>
using namespace std;
bool test(char *a,char *b)
{
	if(*a=='\0' && *b=='\0')
	return 1;
	
	else if(*a=='*' && *(a+1)!='\0' && *b=='\0')
	return 0;
	
	else if(*a=='?' || (*a==*b))
	return test(a+1,b+1);
	
	else if(*a=='*')
	return test(a+1,b)||test(a,b+1);
	
	else return false;
}

int main()
{
	cout<<test("g*k","geeks");
}
