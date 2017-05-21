//Majority element
//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int main()
{
	vector<int> vi,ki;
	int N,x;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>x;
		vi.push_back(x);
	}
	
	sort(vi.begin(),vi.end());
	unique_copy(vi.begin(),vi.end(),back_inserter(ki));
	
	for(int i=0;i<ki.size();++i)
	{
		int p=ki[i];
		int f=upper_bound(vi.begin(),vi.end(),p)-lower_bound(vi.begin(),vi.end(),p);
		if(f>=N/2)
		{
			cout<<p<<endl;
			return 0;
		}
	}
	
}
