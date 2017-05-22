//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
vector<vector<int> > vi;
vector<int> Path;
int marked[100];
int EdgeTo[100];
int main()
{
	int N,M;
	cin>>N>>M;
	vi.resize(N+1);
	int a,b;
	for(int i=1;i<N;++i)
	{
		cin>>a>>b;
		vi[a].push_back(b);
		vi[b].push_back(a);
	}
	long long int ans=1;

	for(int root=1;root<=N;++root)
	{ 
		fill_n(marked,N+1,0);
		fill_n(EdgeTo,N+1,0);
		queue<int> q;
		q.push(root);
		marked[root]=1;
		
		while(!q.empty())
		{
			int k=q.front();
			q.pop();
			for(int i=0;i<vi[k].size();++i)
			{
				if(!marked[vi[k][i]])
				{
					marked[vi[k][i]]=1;
					EdgeTo[vi[k][i]]=k;
					q.push(vi[k][i]);
				}
			}
		}
		
		
		for(int j=root;j<=N;++j)
		{
			for(int p=j;p!=root;p=EdgeTo[p])
			Path.push_back(p);
			Path.push_back(root);
			
			int temp=0;
			int sz=Path.size();
			for(int i=0;i<sz;++i)
					temp+=vi[Path[i]].size();
			temp-=(Path.size()-1)*2;	
			if(temp<=M)ans++;
			Path.clear();
		}
		
	}
cout<<ans<<endl;	
	
}
