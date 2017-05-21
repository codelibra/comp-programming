//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
#include<shiviheaders.h>
using namespace std;
int main()
{
	//MAX heap
	priority_queue<int> pq;
	
	int arr[]={1, 23, 12, 9, 30, 2, 50},k;
	for(int i=0;i<sizeof(arr)/sizeof(int);++i)
	pq.push(arr[i]);
	
	cin>>k;
	for(int i=0;i<k;++i)
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
}
