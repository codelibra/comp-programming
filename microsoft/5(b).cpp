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
			k+=x;
		}
		++N;
		sum=(N*(N+1))/2;
		
		cout<<sum-k;
	
	
	
}
