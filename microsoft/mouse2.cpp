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
#define PAUSE cin.get()
#define START clock_t t1,final;t1=clock();
#define END final=clock()-t1;cout << (double)final / ((double)CLOCKS_PER_SEC);
#define ABS(x) ((x)<0?-(x):(x))
#define fill(a,v) memset(a,v,sizeof a)
#define pf(a) printf("%d",a) 
#define s(n) scanf("%d",&n) 
#define sl(n) scanf("%I64d",&n)
#define pl(a) printf("%I64d",a) 
#define SORT(a) sort(a.begin(),a.end())
#define PRINT(coll) for_each(coll.begin(),coll.end(),printing())
class printing{public: void operator()(int k){pf(k);}};
#define MOD 1000000007
 
 
using namespace std;
int arr[1000][1000];
int dp[1000][1000];
char crr[1000][1000];
void work()
{
	int N,M;
	string str;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i)
	{
		cin>>str;
		for(int k=0;k<str.length();++k)
		{
			arr[i][k]=str[k]-'0';
		}
	}
	
	
	if(N-2>=0 && M-2>=0)
	dp[N-1][M-1]=arr[N-1][M-1]+arr[N-2][M-1]+arr[N-1][M-2];
	else if(N-2>=0)
	dp[N-1][M-1]=arr[N-1][M-1]+arr[N-2][M-1];
	else if(M-2>=0)
	dp[N-1][M-1]=arr[N-1][M-1]+arr[N-1][M-2];
	else
	dp[N-1][M-1]=arr[N-1][M-1];
	
	int a,b,c;
	for(int i=M-2;i>=0;--i)
	{
		crr[N-1][i]='R';
		a=dp[N-1][i+1];
		if(N-2>=0)b=arr[N-2][i];
		else b=0;
		if(i-1>=0)c=arr[N-1][i-1];
		else c=0;
		
		dp[N-1][i]=a+b+c;
	}
	crr[N-1][M-1]='D';
	
	for(int i=N-2;i>=0;--i)
	{
		crr[i][M-1]='D';
		if(i-1>=0)a=arr[i-1][M-1];
		else a=0;
		b=dp[i+1][M-1];
		if(M-2>=0)c=arr[i][M-2];
		else c=0;
		
		dp[i][M-1]=a+b+c;
	}
	
	a=0,b=0,c=0;
	int p=0,q=0,r=0,t=0;
	
	for(int i=N-2;i>=0;--i)
	{
		for(int j=M-2;j>=0;--j)
		{
			if(crr[i][j+1]=='R')
			{
				if(j+1<M)p=dp[i][j+1];
				else p=0;
				if(i+1<N)q=arr[i+1][j];
				else q=0;
				if(j-1>=0)r=arr[i][j-1];
				else r=0;
				if(i-1>=0)t=arr[i-1][j];
				else t=0;
				
				a=p+q+r+t;
			}
			else if(crr[i][j+1]=='D')
			{
				if(j+1<M)p=dp[i][j+1];
				else p=0;
				if(i-1>=0)t=arr[i-1][j];
				else t=0;
				if(j-1>=0)r=arr[i][j-1];
				else r=0;
				
				a=p+r+t;
			}
			else
			{
				int pp,qq,rr,tt;
				if(j+1<M)pp=dp[i][j+1];
				else pp=0;
				if(i+1<N)qq=arr[i+1][j];
				else qq=0;
				if(j-1>=0)rr=arr[i][j-1];
				else rr=0;
				if(i-1>=0)tt=arr[i-1][j];
				else tt=0;
				a=pp+qq+rr+tt;
				
				if(j+1<M)pp=dp[i][j+1];
				else pp=0;
				if(i-1>=0)tt=arr[i-1][j];
				else tt=0;
				if(j-1>=0)rr=arr[i][j-1];
				else rr=0;
				a=min(a,pp+rr+tt);
			}
			
			if(crr[i+1][j]=='R')
			{
				if(i+1<N)p=dp[i+1][j];
				else p=0;
				if(j-1>=0)q=arr[i][j-1];
				else q=0;
				if(i-1>=0)r=arr[i-1][j];
				else r=0;
				
				b=p+q+r;
			}
			else if(crr[i+1][j]=='D')
			{
				if(i+1<N)p=dp[i+1][j];
				else p=0;
				if(j-1>=0)q=arr[i][j-1];
				else q=0;
				if(i-1>=0)r=arr[i-1][j];
				else r=0;
				if(j+1<M)t=arr[i][j+1];
				else t=0;
				
				b=p+q+r+t;
			}
			else
			{
				int pp,qq,rr,tt;
				if(i+1<N)pp=dp[i+1][j];
				else pp=0;
				if(j-1>=0)qq=arr[i][j-1];
				else qq=0;
				if(i-1>=0)rr=arr[i-1][j];
				else rr=0;
				b=pp+qq+rr;
				
				if(i+1<N)pp=dp[i+1][j];
				else pp=0;
				if(j-1>=0)qq=arr[i][j-1];
				else qq=0;
				if(i-1>=0)rr=arr[i-1][j];
				else rr=0;
				if(j+1<M)tt=arr[i][j+1];
				else tt=0;
				b=min(b,pp+qq+rr+tt);
				
			}
			
			if(a<b)
			{
				crr[i][j]='R';
				dp[i][j]=a;
			}
			else if(a>b)
			{
				crr[i][j]='D';
				dp[i][j]=b;
			}
			else
			{
				crr[i][j]='A';
				dp[i][j]=b;
			}
		}
	}
	printf("%d\n",dp[0][0]);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	work();
}
 