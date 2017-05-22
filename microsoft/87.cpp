//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;

string Next(string str)
{
	int i=0,l=str.length();
	bool possible=0;
	while( l-i-2>=0 && str[l-i-1]<str[l-i-2]) ++i;
	++i;
	if(i>=l)exit(0);
	
	swap(str[l-1],str[l-i-1]);
	sort(str.begin()+(l-i),str.end());
	cout<<str<<endl;
	getch();
	return Next(str);
}

int main()
{
	
}
