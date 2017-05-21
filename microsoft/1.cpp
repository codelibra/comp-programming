//http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int main()
{
	vector<int> vi;
	int N,x,sum;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>x;
		vi.push_back(x);
	}
	
	sort(vi.begin(),vi.end());
	
	int i=0,j=vi.size()-1;
	cin>>sum;
	while(i<j)
	{
		if(vi[i]+vi[j]>sum)
		--j;
		else if(vi[i]+vi[j]<sum)
		++i;
		else
		{
			cout<<vi[i]<<" "<<vi[j]<<" "<<sum<<endl;
			return 0;
		}
	}
	cout<<"sum not found\n";
	}
