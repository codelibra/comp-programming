//shivi..coding is adictive!!
//dynamic-programming-set-12-longest-palindromic-subsequence/
#include<shiviheaders.h>
using namespace std;
int lps[100][100];
int main()
{
	string str;
	cin>>str;
	int n=str.length();
	for(int i=0;i<n;++i)lps[i][i]=1;
	
	//len is length of substring we r using
	for(int len=2;len<=n;++len)
	{
		for(int i=0;i<n-len+1;++i)
		{
			int j=len+i-1;
			if(str[i]==str[j] && len==2)
			lps[i][j]=2;
			
			else if(str[i]==str[j])
			lps[i][j]=lps[i+1][j-1]+2;
			
			else
			lps[i][j]=max(lps[i][j-1], lps[i+1][j]);
			
		}
	}
	
	cout<<lps[0][n-1];
}

