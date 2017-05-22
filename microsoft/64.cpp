//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/print-unique-rows/
#include<shiviheaders.h>
using namespace std;
int main()
{
	set<string> k;
	char str[100];
	int N;
	cin>>N;
	for(int i=0; i<N;++i)
	{
		fflush(stdin);
		gets(str);
		k.insert(str);
	}
	
	set<string>::iterator itr;
	for(itr=k.begin();itr!=k.end();++itr)
	cout<<*itr<<endl;
	
	
}
