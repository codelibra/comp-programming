//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
#include<shiviheaders.h>
using namespace std;
int main()
{
	//MAX heap
	priority_queue<int,vector<int>,greater<int> > pq;
	
	int arr[]={1, 23, 12, 9, 30, 2, 50},k;
	cin>>k;
	for(int i=0;i<k;++i)
	pq.push(arr[i]);
	
	for(int i=k;i<sizeof(arr)/sizeof(int);++i)
	{
		if(arr[i]>pq.top())
		{pq.pop();pq.push(arr[i]);}
	}
	
	for(int i=0;i<k;++i)
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
}
