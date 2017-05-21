//shivi..coding is adictive!!
//Print all permutations with repetition of characters
#include<shiviheaders.h>
using namespace std;
void permute(char *str,char* data,int index,int len)
{
	for(int i=0;i<=len;++i)
	{
		data[index]=str[i];
		if(index==len)
		{data[len+1]='\0';cout<<data<<endl;}
		else
		permute(str,data,index+1,len);
	}
}

int main()
{
	char str[50],data[50];
	cin>>str;
	int len = strlen (str) ;
	permute(str,data,0,len-1);
}
