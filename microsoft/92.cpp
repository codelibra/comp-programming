//shivi..coding is adictive!!
//Check whether a given string is an interleaving of two other given strings
#include<shiviheaders.h>
using namespace std;
int main()
{
	string str1,str2,str3;
	cin>>str1>>str2>>str3;
	
	int i=0,j=0,k=0;
	
	while(k<str3.length())
	{
		if(str3[k]!=str1[i] && str3[k]!=str2[j])
		{cout<<"Not"; return 0;}
		
		else if(str3[k]==str1[i])
		++i;
		
		else if(str3[k]==str2[j])
		++j;
		
		++k;
	}
	
	cout<<"yes";
}
