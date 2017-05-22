//shivi..coding is adictive!!
//Naive Pattern Searching
#include<shiviheaders.h>
using namespace std;

void search(char *patt,char *text)	
{
	int ans=1,i;
	
	for(i=0;i<strlen(text)-strlen(patt);++i)
	{
		ans=1;
		for(int j=0;j<strlen(patt);++j)
		{
			if(patt[j]!=text[i+j])
			{
				ans=0;
				break;
			}
		}
		if(ans)
		{
			cout<<"patt found at "<<i;
			break;
		}
	}
}

int main()
{
	search("AABA","AABAACAADAABAAABAA");
}
