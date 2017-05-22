//shivi..coding is adictive!!
//Count words in a given string
#include<shiviheaders.h>
#define IN 0
#define OUT 1
using namespace std;
int main()
{
	char str[100];
	gets(str);
	int state=OUT,ans=0;
	
	for(int i=0;str[i]!='\0';++i)
	{
		if(str[i]==' ' || str[i]=='\t' || str[i]=='\n')
		state=OUT;
		
		else if(state==OUT)
		{
			state=IN;
			++ans;
		}
	}
	cout<<ans;
}
