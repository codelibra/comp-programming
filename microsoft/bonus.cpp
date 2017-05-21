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
	bool useable=0;
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
	
	for(int i=1;i<=N;++i)
	{ 
		useable=0;
		//cout<<"root "<<i<<endl;
		fill_n(marked,N+1,0);
		fill_n(EdgeTo,N+1,0);
		queue<int> q;
		q.push(i);
		marked[i]=1;
		
		while(!q.empty())
		{
			int k=q.front();
			q.pop();
			//cout<<k<<endl;
			
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
		
		
		for(int j=1;j<=N;++j)
		{
			if(!marked[j])continue;
			for(int p=j;p!=i;p=EdgeTo[p])
			Path.push_back(p);
			Path.push_back(i);
			
			int temp=0;
			int sz=Path.size();
			if(sz==1) useable=1;
			
			if(useable)
			{
				for(int i=0;i<sz;++i)
				{
					//cout<<Path[i]<<" ";
					temp+=vi[Path[i]].size();
				}
				temp-=(Path.size()-1)*2;	
				if(temp<=M)ans++;
				//cout<<temp<<" "<<ans;
				//cout<<endl;
			}
			Path.clear();
		}
		
	}
cout<<ans<<endl;	
	
}
