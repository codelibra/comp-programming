//shivi..coding is adictive!!
//Longest Common Substring
#include<shiviheaders.h>
using namespace std;
int LCS[100][100];
int main()
{
	char str1[100],str2[100];
	cin>>str1>>str2;
	int m=strlen(str1),n=strlen(str2),ans=0;
	
	for(int i=0;i<=m;++i)
	{
		for(int j=0;j<=n;++j)
		{
			if(i==0 || j==0)
			LCS[i][j]=0;
			
			if(str1[i-1]==str2[j-1])
			{
				LCS[i][j]=1+LCS[i-1][j-1];
				ans=max(ans,LCS[i][j]);
			}
			
			else
			LCS[i][j]=0;
		}
	}
	
	cout<<ans;
	
}
