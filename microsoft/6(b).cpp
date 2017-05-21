//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
#include<shiviheaders.h>
using namespace std;
int arr[100000];
int N;
int BinarySearch(int lo,int hi,int num)
{
	if(lo>hi) return -1;
	int mid=(lo+hi)/2;
	if(arr[mid]>num)   return  BinarySearch(lo,mid-1,num);
		
	else if(arr[mid]<num)return BinarySearch(mid+1,hi,num);
	
	else return mid+1;
	
}
int main()
{
		vector<int> vi;
		int x,sum;
		cin>>N;
		for(int i=0;i<N;++i)
		{
			cin>>x;
			arr[i]=x;
		}
		
	sort(arr,arr+N);	
	if(BinarySearch(0,N-1,12)!=-1)
	cout<<BinarySearch(0,N-1,12);
	
}
