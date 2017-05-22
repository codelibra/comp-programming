//shivi..coding is adictive!!
//Print all interleavings of given two strings
#include<shiviheaders.h>
using namespace std;
char str1[20],str2[20],str3[20];
void print(char * str1,char * str2,char* str3,int m,int n,int k)
{
	cout<<str1<<" "<<str2<<" "<<str3<<endl;
	if(m==0 && n==0)
	cout<<str3<<endl;
	
	if(m!=0)
	{
	str3[k]=str1[0];
	print(str1+1,str2,str3,m-1,n,k+1);
	}
		
	if(n!=0)
	{
	str3[k]=str2[0];
	print(str1,str2+1,str3,m,n-1,k+1);
	}
}

int main()
{
	char str1[20],str2[20];
	cin>>str1>>str2;
	int i=0,j=0,k=0;
	//char *str3=(char *)malloc((strlen(str1)+strlen(str2))*sizeof(char));
	str3[strlen(str1)+strlen(str2)]='\0';
	
	print(str1,str2,str3,strlen(str1),strlen(str2),k);
}
