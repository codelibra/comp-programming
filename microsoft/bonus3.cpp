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

vector<vector<int> > vi;
vector<int> Path;
vector<int> Tree;
int marked[100];
int visited[100];

bool CheckTree(vector<int> &ki)
{
	for(int i=0;i<ki.size();++i)
		if(visited[ki[i]]==0) return 1;
		
	return 0;
}

int main()
{
	int N,M;
	static int num=1;
	cin>>N>>M;
	vi.resize(N+1);
	int a,b;
	for(int i=1;i<N;++i)
	{
		cin>>a>>b;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}
	
	long long int ans=0;
	
	for(int root=1;root<=N;++root)
	{ 
		cout<<"root "<<root<<endl;
		fill_n(marked,N+1,0);
		queue<int> q;
		q.push(root);
		marked[root]=1;
		
		while(!q.empty())
		{
			int k=q.front();
			Tree.push_back(k);
			visited[k]=1;
			q.pop();
			for(int i=0;i<vi[k].size();++i)
			{
				if(!marked[vi[k][i]])
				{
					marked[vi[k][i]]=1;
					q.push(vi[k][i]);
				}
			}
			int val=0;
			int sz=Tree.size();
			
			for(int i=0;i<sz;++i)val+=vi[Tree[i]].size();
			val-=(Tree.size()-1)*2;	
			if(val<=M)
			{
				ans++;
				for(int i=0;i<Tree.size();++i)
				cout<<Tree[i]<<" ";
				cout<<endl;
			}
			
		}
		Tree.clear();
	}
	
cout<<ans<<endl;
	
}
