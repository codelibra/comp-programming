//shivi..coding is adictive!!
//test wheather 2 strings are roations of each other!
#include<shiviheaders.h>
using namespace std;
int main()
{
	char str1[100],str2[100];
	cin>>str1>>str2;
	
	int l=strlen(str1);
	char *temp,*temp2;
	temp=new char[2*l*sizeof(char)+1];
	temp[0]='\0';
	strcat(temp,str1);strcat(temp,str1);
	
	temp2=strstr(temp,str2);
	if(temp2)
	cout<<"yes";
	else
	cout<<"no";
}

