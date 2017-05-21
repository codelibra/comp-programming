//shivi..coding is adictive!!
//Find the smallest window in a string containing all characters of another string
#include<shiviheaders.h>
using namespace std;
string str1,str2;
int hash1[26];
int hash2[26];
bool check()
{
	for(int i=0;i<26;++i)
	if(hash2[i]<hash1[i]) return 0;
	
	return 1;
}

int main()
{
	cin>>str1>>str2;
	for(int i=0;i<str1.length();++i) hash1[str1[i]-'a']++;
	int i,j,min_len;
	for(i=0;i<str2.length();++i)
	{
		hash2[str2[i]-'a']++;
		if(check())break;
	}
	j=i,i=0;
	min_len=j-i+1;
	
	while(j<=str2.length())	
	{
		++j;
		if(j==str2.length())break;
		if(str2[j]==str1[str1.length()-1])
		{
			hash2[str2[j]-'a']++;
			while(i<=j)
			{
				if(hash1[str2[i]-'a']>0 && hash1[str2[i]-'a']==hash2[str2[i]-'a'])break;
				else
				{
					hash2[str2[i]-'a']--;
					++i;
				}
			}
			min_len=min(min_len,j-i+1);
		}
		else
		hash2[str2[j]-'a']++;
	}
	
	cout<<min_len<<endl;
}
