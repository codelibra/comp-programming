//shivi..coding is adictive!!
//Longest Palindromic Substring
#include<shiviheaders.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int max_len=1,lo,hi;
	for(int i=1;i<str.length();++i)
	{
		//odd length
		lo=i-1;
		hi=i+1;
		
		while(lo>=0 && hi<=str.length() && str[lo]==str[hi])
		{
			if(hi-lo+1>max_len)
			max_len=hi-lo+1;
			--lo;
			++hi;
		}
		
		
		//even length
		lo=i;
		hi=i+1;
		
		while(lo>=0 && hi<=str.length() && str[lo]==str[hi])
		{
			if(hi-lo+1>max_len)
			max_len=hi-lo+1;
			--lo;
			++hi;
		}
	}
	cout<<max_len<<endl;
}
