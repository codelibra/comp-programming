//http://www.geeksforgeeks.org/find-the-missing-number/
//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int main()
{
		vector<int> vi;
		int N,x,sum,k=0;
		cin>>N;
		for(int i=0;i<N;++i)
		{
			cin>>x;
			k^=x;
			vi.push_back(x);
		}
	
	int XOR=0;	
	for(int i=1;i<=N+1;++i)
	XOR^=i;
	
	cout<<(XOR^k)<<endl;
	
}
