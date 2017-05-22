//Majority element
//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int main()
{
	vector<int> vi;
	int N,x;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>x;
		vi.push_back(x);
	}
	
	int maj_index=0,maj_count=1;
	
	//Moore's voting algo
	for(int i=1;i<N;++i)
	{
		if(vi[i]==vi[maj_index])
		++maj_count;
		else if(maj_count>1)
		--maj_count;
		else
		{
			maj_count=1;
			maj_index=i;
		}
	}
	
	cout<<vi[maj_index];
}
