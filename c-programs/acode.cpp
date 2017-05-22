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
int matrix[5002][5002];
void Preprocess()
{
	for(int i=0;i<=5000;++i)
	{
		for(int j=0;j<=5000;++j)	
		{
			matrix[i][j]=0;
			matrix[i][i]=1;
		}
	}
}

int NumberOfWays(int lo,int hi,string s)
{
	if(lo>hi) return 1;
	
	if(matrix[lo][hi]!=0)
	return matrix[lo][hi];
	
	if(lo==hi) return 1;
	
	if(hi==lo+1)
	{
		int x=s[lo]-'0';
		int y=s[hi]-'0';
		if(10*x+y<=25) return 2;
		else return 1;
	}
	
	int mid=lo+(hi-lo)/2;
	
	int l,r;
	if(matrix[lo][mid]!=0) l=matrix[lo][mid];
	else
	{
		matrix[lo][mid]=NumberOfWays(lo,mid,s);
		l=matrix[lo][mid];
	}
	
	if(matrix[mid+1][hi]!=0) r=matrix[mid+1][hi];
	else
	{
		matrix[mid+1][hi]=NumberOfWays(mid+1,hi,s);
		r=matrix[mid+1][hi];
	}
	
	int x=s[mid]-'0',y=s[mid+1]-'0';
	
	if(10*x+y<=25) 
	{
		int a=matrix[lo][mid-1],b=matrix[mid+2][hi];
		if(a==0)
		{
		matrix[lo][mid-1]=NumberOfWays(lo,mid-1,s);
		a=matrix[lo][mid-1];
		}
		
		if(b==0)
		{
		matrix[mid+2][hi]=NumberOfWays(mid+2,hi,s);
		b=matrix[mid+2][hi];
		}
		
		return l*r+a*b;
	}
	else
	{
		return l*r;
	}
}
int main()
{
	
	string str;
	while(1)
	{
	cin>>str;
	if(str[0]=='0')break;
	
	Preprocess();
	int len=str.length();
	cout<<NumberOfWays(0,len-1,str)<<endl;
	}
}
