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
	cin>>N>>M;
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
		if(i+1<N)b=dp[i+1][M-1];
		else b=0;
		if(M-2>=0)c=arr[i][M-2];
		else c=0;
		
		dp[i][M-1]=a+b+c;
	}
	
	/*
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			cout<<crr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	*/
	
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
			else
			{
				if(j+1<M)p=dp[i][j+1];
				else p=0;
				if(i-1>=0)t=arr[i-1][j];
				else t=0;
				if(j-1>=0)r=arr[i][j-1];
				else r=0;
				
				a=p+r+t;
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
			else
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
			/*else
			{
				//fucking case!!
				/*cout<<"hi";
				int x=0,y=0,z=0,w=0,aa=0,bb=0,dd=0,ee=0;
				
				if(j-2>=0)x=arr[i][j-2];
				if(i-1>=0 && j-1>=0) y=arr[i-1][j-1];
				if(i+1<N && j-1>=0) z=arr[i+1][j-1];
				if(i-2>=0) w=arr[i-2][j];
				
				
				if(j-2>=0)aa=arr[i][j-2];
				if(i-1>=0 && j-1>=0) bb=arr[i-1][j-1];
				if(i-2>=0)dd=arr[i-2][j];
				if(i-1>=0 && j+1<M)ee=arr[i-1][j+1];
				
				
				int x=0,y=0;
				if(i-1>=0 && j+1<M)x=arr[i-1][j+1];
				if(i+1<N && j-1>=0)y=arr[i+1][j-1];
				   
				//int p=x+y+z+w;//R
				//int q=aa+bb+dd+ee;//D
				
				//if(x<y)crr[i][j]='D';
				//else crr[i][j]='R';
				crr[i][j]='R';
				//cout<<p<<" "<<q<<" "<<i<<" "<<j<<endl;
				
			}*/
		}
	}
	
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			cout<<crr[i][j]<<" ";
		}
		cout<<endl;
	}
	

	cout<<dp[0][0]<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	work();
}
