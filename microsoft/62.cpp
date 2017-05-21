//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/nearly-sorted-algorithm/
#include<shiviheaders.h>
using namespace std;
int main()
{
	priority_queue<int,vector<int> ,greater<int> > p;
	int arr[100],N,k,i;
	cin>>N;
	for(int i=0;i<N;++i)cin>>arr[i];
	
	cin>>k;
	for(i=0;i<k;++i)p.push(arr[i]);
	
	for(;i<N;++i)
	{
		p.push(arr[i]);
		cout<<p.top()<<endl;
		p.pop();
	}
	while(!p.empty())
	{
		cout<<p.top()<<endl;
		p.pop();
	}
	
}
