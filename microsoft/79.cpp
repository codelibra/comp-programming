//shivi..coding is adictive!!
//atoi function
#include<shiviheaders.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int ans=0;
	
	for(int i=0;i<str.length();++i)
	{
		ans=ans*10+str[i]-'0';
	}
	cout<<ans<<endl;
	
	ans=0;
	for(int i=0;i<str.length();++i)
	{
		ans+=(str[i]-'0')*pow(10.0,(int)str.length()-i-1);
	}
	cout<<ans;
}
