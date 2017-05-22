//shivi..coding is adictive!!
//atoi function  handle negetive numbers and null string
#include<shiviheaders.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int ans=0,k=1,start=0,err=0;
	
	
	if(str[0]=='-'){k=-1;++start;}
	
	for(int i=start;i<str.length();++i)
	{
		if(str[i]>='9' ||str[i]<='0') 
		{
			err=1;
			break;
		}
		ans=ans*10+str[i]-'0';
	}
	if(!err)
	cout<<ans*k<<endl;
	else 
	cout<<"error";
	
	ans=0;
	for(int i=start;i<str.length();++i)
	{
		if(str[i]>='9' ||str[i]<='0') 
		{
			err=1;
			break;
		}
		ans+=(str[i]-'0')*pow(10.0,(int)str.length()-i-1);
	}
	if(!err)
	cout<<ans*k;
	else 
	cout<<"error";
}
