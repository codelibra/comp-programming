//shivi..coding is adictive!!
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<climits>
#include<iterator>
#include<string>
#include<list>
#include<functional>
#include<bitset>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<numeric>
#define MOD 1000000007

using namespace std;
int two[1010][1010];
int five[1010][1010];
long long int value[1010][1010];
char path2[1010][1010];
char path5[1010][1010];
int N,zerox,zeroy;
bool present=0;
int power(long long int val,long long int n)
{
	int ans=0,temp=n;
	while(1)
	{
		if(val%n==0) ++ans;
		else break;
		n*=temp;
	}
	return ans;
}

void Dynamic()
{
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N ;++j)
		{
			five[i][j]=power(value[i][j],5);
			two[i][j]=power(value[i][j],2);
		}
	}
	
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			if(i==0 && j==0) 
			{
				path2[i][j]='\0';
				path5[i][j]='\0';
			}
			
			else if(i==0)
			{
				five[i][j]+=five[i][j-1];
				two[i][j]+=two[i][j-1];
				path2[i][j]='R';
				path5[i][j]='R';
			}
			
			else if(j==0)
			{
				five[i][j]+=five[i-1][j];
				two[i][j]+=two[i-1][j];
				path2[i][j]='D';
				path5[i][j]='D';
			}
			
			else
			{
				int p=five[i-1][j],q=five[i][j-1];
				int a=two[i-1][j],b=two[i][j-1];
				
				if(p<q) path5[i][j]='D';
				else path5[i][j]='R';
				
				if(a<b) path2[i][j]='D';
				else path2[i][j]='R';
				
				five[i][j]+=min(p,q);
				two[i][j]+=min(a,b);
			}
		}
	}
/*	
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			cout<<matrix[i][j].m<<","<<matrix[i][j].n<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			cout<<path[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	
	if(present==1 && min(five[N-1][N-1],two[N-1][N-1])>1)
	{
		cout<<"1\n";
		string str="",str2="";
		int i=zerox,j=zeroy;
		while(i>0 || j>0)
		{
			//cout<<i<<" "<<j<<endl;
			str+=path2[i][j];
			if(path2[i][j]=='R')
			j=j-1;
			else
			i=i-1;
		}
		reverse(str.begin(),str.end());
		for(;zeroy+1<N;++zeroy)str+='R';
		for(;zerox+1<N;++zerox)str+='D';
		cout<<str;
		return;
	}
	
	cout<<min(five[N-1][N-1],two[N-1][N-1])<<endl;
	int i=N-1,j=N-1;
	string str="";
	
	if(five[N-1][N-1]<two[N-1][N-1])
	{
		while(i>0 || j>0)
		{
		//cout<<i<<" "<<j<<endl;
			str+=path5[i][j];
			if(path5[i][j]=='R')
			j=j-1;
			else
			i=i-1;
		}
	reverse(str.begin(),str.end());
	cout<<str;
	}
	else
	{
		while(i>0 || j>0)
		{
		//cout<<i<<" "<<j<<endl;
			str+=path2[i][j];
			if(path2[i][j]=='R')
			j=j-1;
			else
			i=i-1;
		}
	reverse(str.begin(),str.end());
	cout<<str;
	}
}

int main()
{
	cin>>N;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			cin>>value[i][j];
			if(value[i][j]==0)
			{
				present=1;
				zerox=i;
				zeroy=j;
				value[i][j]=10;
			}
		}
	}
	Dynamic();
}
