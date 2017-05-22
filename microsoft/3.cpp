//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/find-the-number-occurring-odd-number-of-times/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,x,k=0;
	cin>>N;
	vector<int> vi;
	for(int i=0;i<N;++i)
	{
		cin>>x;
		vi.push_back(x);
	}
	
	for(int i=0;i<N;++i)
	k^=vi[i];
	
	cout<<k<<endl;
}
