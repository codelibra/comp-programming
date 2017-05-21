//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,k,i;
	cin>>N>>k;
	int arr[100];
	for(int i=0;i<N;++i)cin>>arr[i];
	
	deque<int> d;
	for(i=0;i<k;++i)
	{
		while(d.size()>0 && arr[d.back()]<arr[i])
		d.pop_back();
		
		d.push_back(i);
	}
	
	for(;i<N;++i)
	{
		cout<<arr[d.front()]<<" ";
		
		while(d.size()>0 && d.front()<=i-k)
		d.pop_front();
		
		while(d.size()>0 && arr[d.back()]<arr[i])
		d.pop_back();
		
		d.push_back(i);
	}
	cout<<arr[d.front()]<<" ";
}
