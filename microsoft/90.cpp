//shivi..coding is adictive!!
//Length of the longest substring without repeating characters
#include<shiviheaders.h>
using namespace std;
int hash[26];
int main()
{
	string str;
	cin>>str;
	int i=0,j=0,maxlen=1;;
	hash[str[0]-'A']++;
	while(i<str.length() && j<=i)
	{
		++i;
		if(i>=str.length()) break;
		
		else if(hash[str[i]-'A']==0)
		{
			hash[str[i]-'A']++;
		}
		else
		{
			while(str[j]!=str[i])
			{
				hash[str[j]-'A']--;
				++j;
			}
			
			++j;
		}
		maxlen=max(i-j+1,maxlen);
	}
	cout<<maxlen;
}
