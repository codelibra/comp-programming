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
int  arr[100000];
bool dp1[1000][1000];
bool dp2[1000][1000];
void SubsetSum(int N,int sum)
{
	vector<int> positive;
	vector<int> negetive; 
	int posmax=0,negmax=0;
	
	for(int i=0;i<N;++i)
	{
		if(arr[i]>=0)
		{
			positive.push_back(arr[i]);
			posmax+=arr[i];
		}
		else
		{
			negetive.push_back(abs(arr[i]));
			negmax+=abs(arr[i]);
		}
	}
	
	for(int i=0;i<100;++i)	
	{
		for(int j=0;j<100;++j)
		{
			dp1[i][j]=0;
			dp2[i][j]=0;
		}
	}
	
	
	for(int i=0;i<=positive.size();++i)
	dp1[0][i]=1;
	
	for(int i=0;i<=negetive.size();++i)
	dp2[0][i]=1;
	
	for(int i=1;i<=posmax;++i)
	dp1[i][0]=0;
	
	for(int i=1;i<=negmax;++i)
	dp2[i][0]=0;
	
	
	
	vector<int> pplus;
	vector<int> nminus;	
	pplus.push_back(1);
	nminus.push_back(1);
	
	for(int i=1;i<=posmax;++i)
	{
		for(int j=1;j<=positive.size();++j)
		{
			dp1[i][j]=dp1[i][j-1];
			
			if(positive[j-1]<=i)
				dp1[i][j]=dp1[i][j] || dp1[i-positive[j-1]][j-1];
			if(j==positive.size()) pplus.push_back(dp1[i][j]);
		}
	}
	
	for(int i=1;i<=negmax;++i)
	{
		for(int j=1;j<=negetive.size();++j)
		{
			dp2[i][j]=dp2[i][j-1];
			
			if(negetive[j-1]<=i)
				dp2[i][j]=dp2[i][j] || dp2[i-negetive[j-1]][j-1];
			
			if(j==negetive.size()) nminus.push_back(dp2[i][j]);
		}
	}
	
	if(sum>posmax) cout<<"NO\n";
	
	for(int i=sum;i<pplus.size();++i)
	{
		if(pplus[i] && i-sum<nminus.size() && nminus[i-sum])
		{
			cout<<"YES\n";
			positive.clear();
			negetive.clear();
			pplus.clear();
			nminus.clear();
			return ;
		}
	}
	      	positive.clear();
			negetive.clear();
			pplus.clear();
			nminus.clear();
		
cout<<"NO\n";	
return;

}
int main()
{
	int t,N,sum;
	cin>>t;
	while(t--)
	{
		cin>>N;
		for(int i=0;i<N;++i)
		cin>>arr[i];
		cin>>sum;
		SubsetSum(N,sum);
	}
	
}
