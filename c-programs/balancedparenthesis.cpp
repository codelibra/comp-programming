//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
void BalncedParenthsis(int open1,int close1,int open2,int close2,int open3,int close3,int N,char data[],int index)
{
	if(close1==N && close2==N && close3==N)
	{
		for(int i=0;i<index;++i)
		cout<<data[i];
		cout<<endl;
		return;
	}
	
	if(open1>close1 && open2==close2 && open3==close3)
	{
		data[index]=']';
		BalncedParenthsis(open1,close1+1,open2,close2,open3,close3,N,data,index+1);
	}
	
	if(open1<N && open2==close2 && open3==close3)
	{
		data[index]='[';
		BalncedParenthsis(open1+1,close1,open2,close2,open3,close3,N,data,index+1);
	}
	
	if(open2>close2 && open3==close3)
	{
		data[index]='}';
		BalncedParenthsis(open1,close1,open2,close2+1,open3,close3,N,data,index+1);
	}
	
	if(open2<N && open3==close3)
	{
		data[index]='{';
		BalncedParenthsis(open1,close1,open2+1,close2,open3,close3,N,data,index+1);
	}
	
	if(open3>close3)
	{
		data[index]=')';
		BalncedParenthsis(open1,close1,open2,close2,open3,close3+1,N,data,index+1);
	}
	if(open3<N)
	{
		data[index]='(';
		BalncedParenthsis(open1,close1,open2,close2,open3+1,close3,N,data,index+1);
	}
}
int main()
{
	char data[100];
	BalncedParenthsis(0,0,0,0,0,0,1,data,0);
}
