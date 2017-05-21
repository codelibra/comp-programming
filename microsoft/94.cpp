//shivi..coding is adictive!!
//Lexicographic rank of a string
#include<shiviheaders.h>
using namespace std;
int hash[26];
int fact(int n)
{
    return (n <= 1)? 1 :n * fact(n-1);
}
string str;

int fun(int i)
{
	int ans=0;
	for(int p=0;p<i;++p)
		if(str[p]<str[i])++ans;
	return ans;
}

int main()
{
	cin>>str;
	for(int i=0;i<str.length();++i)hash[str[i]-'a']++;
	
	for(int i=1;i<26;++i)hash[i]+=hash[i-1];
	
	int rank=0;
	for(int i=0;i<str.length();++i)
	{
		rank+=(hash[str[i]-'a']-fun(i)-1)*fact(str.length()-i-1);
	}
	cout<<rank+1;
	
}
