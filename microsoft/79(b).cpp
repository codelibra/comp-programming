//shivi..coding is adictive!!
//atoi function  handle negetive numbers
#include<shiviheaders.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int ans=0,k=1,start=0;
	
	
	if(str[0]=='-'){k=-1;++start;}
	
	for(int i=start;i<str.length();++i)
	{
		ans=ans*10+str[i]-'0';
	}
	cout<<ans*k<<endl;
	
	ans=0;
	for(int i=start;i<str.length();++i)
	{
		ans+=(str[i]-'0')*pow(10.0,(int)str.length()-i-1);
	}
	cout<<ans*k;
}
