//shivi..coding is adictive!!
//Add two bit strings
#include<shiviheaders.h>
using namespace std;
int main()
{
	string a,b,ans,temp;
	int carry =0;
	
	
	cin>>a>>b;
	int l1=a.length(),l2=b.length();
	if(l1<l2)
	{
		for(int i=0;i<l2-l1;++i)temp.push_back('0');
		for(int i=0;i<l1;++i)temp.push_back(a[i]);
		a=temp;
	}
	else
	{
		for(int i=0;i<l1-l2;++i)temp.push_back('0');
		for(int i=0;i<l2;++i)temp.push_back(b[i]);
		b=temp;
	}
	
	cout<<a<<endl<<b<<endl;;
	for(int i=max(l2,l1)-1;i>=0;--i)
	{
		int firstbit=a[i]-'0';
		int secondbit=b[i]-'0';
		
		int sum=firstbit^secondbit^carry+'0';
		ans.push_back((char)sum);
		
		carry=(firstbit&secondbit)|(secondbit&carry)|(carry&firstbit);
		cout<<firstbit<<" "<<secondbit<<" "<<carry<<" "<<(char)sum<<endl;
	}
	
	if(carry)
	ans=ans+'1';
	reverse(ans.begin(),ans.end());
	cout<<endl<<ans;
}
