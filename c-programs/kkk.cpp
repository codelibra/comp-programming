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
int visited[1010][1010];
int N,M;
void Clearvisited()
{
	for(int i=0;i<=N;++i)
	{
		for(int j=0;j<=M;++j)
		{
			visited[i][j]=0;
		}
	}
}
char matrix[1010][1010];
int x[]={-1,0,1,0};
int y[]={0,-1,0,1};
char search(char c)
{
	if(c=='D') return  'I';
	if(c=='I') return  'M';
	if(c=='M') return  'A';
	if(c=='A') return  'D';
}

bool isSafe(int i,int j,char c)
{
	if(i<0 || j<0 || i>=N || j>=M)
	return 0;
	
	if(matrix[i][j]!=search(c))
	return 0;
	
	return 1;
}

bool cyclic=0;
int maxcount=0,count=0;
void dfs(int i,int j,int &count)
{
	//cout<<i<<" "<<j<<endl;
	if(cyclic) return;
	
	visited[i][j]=1;
	char c=matrix[i][j];
	if(c=='A') 
	{
		++count;
		if(maxcount<count)maxcount=count;
	}
	
	bool found=0;
	for(int k=0;k<4;++k)
	{
		if(isSafe(i+x[k],j+y[k],c) && !visited[i+x[k]][j+y[k]])
		{
			found=1;
			dfs(i+x[k],j+y[k],count);
		}
		else if(isSafe(i+x[k],j+y[k],c) && visited[i+x[k]][j+y[k]])
		{
			cyclic=1;
			return;
		}
	}
	if(!found)
	{
		visited[i][j]=0;
		if(c=='A')--count;
	}
}

int Find()
{
	int c;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			c=0;
			if(!visited[i][j] && matrix[i][j]=='D')
			dfs(0,0,c);
			//Clearvisited();
		}
	}
	return maxcount;
}

int main()
{
	cin>>N>>M;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<M;++j)
		{
			cin>>matrix[i][j];
		}
	}
	
	int k;
	k=Find();
	
	if(k==0)
	cout<<"Poor Dima!";
	else if(cyclic)
	cout<<"Poor Inna!";
	else 
	cout<<k;
	
}
