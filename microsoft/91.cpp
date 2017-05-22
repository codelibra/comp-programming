//shivi..coding is adictive!!
///Print all permutations in sorted (lexicographic) order
#include<shiviheaders.h>
using namespace std;
bool check(string str)
{
	for(int i=0;i<str.length();++i)
	if(str[i]<str[i+1]) return 1;
	return 0;
}

bool Next(string &str)
{
	int i=str.length()-1;
	while(str[i]<=str[i-1])--i;
	--i;
	int k=str.length()-1;
	while(str[k]<=str[i])--k;
	swap(str[k],str[i]);
	reverse(str.begin()+i+1,str.end());
	return check(str);
}

int main()
{
	string str,str2;
	cin>>str;
	
	while(Next(str))
	cout<<str<<endl;
}
