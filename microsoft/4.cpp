//shivi..coding is adictive!!
//kadane's algorithm
//not hadling negetive numbers
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
		
	int max_ending_here=0,max_so_far=0;
	
	for(int i=0;i<N;++i)
	{
		max_so_far+=vi[i];
		
		if(max_so_far<0)
		max_so_far=0;
		
		if(max_ending_here<max_so_far)
		max_ending_here=max_so_far;
	}
	
	cout<<max_ending_here;
}
