//shivi..coding is adictive!!
//reverse of string
#include<shiviheaders.h>
using namespace std;
string str;
void print(int i)
{
	if(str[i]=='\0') return;
	else
	{
		print(i+1);
		cout<<str[i];
	}
}
int main()
{
	cin>>str;
	print(0);
}
