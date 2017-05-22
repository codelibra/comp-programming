//shivi..coding is adictive!!
//Reverse words in a given string
#include<shiviheaders.h>
using namespace std;
int main()
{
	char str[1000];
	gets(str);
	vector<string> vi;
	string s;
	int start=0,j,i;
	
	for(i=0;i<strlen(str);++i)
	{
		if(str[i]==' ')
		{
			for(j=i-1;j>=start;--j)
			s+=str[j];
			start=i+1;
			
			vi.push_back(s);
			s.clear();
		}
	}
	for(j=i-1;j>=start;--j)
	s+=str[j];
	start=i+1;
	vi.push_back(s);
	
	string ans;
	for(int i=0;i<vi.size();++i)
	ans+=vi[i]+' ';
	
	reverse(ans.begin(),ans.end());
	cout<<ans;
}
