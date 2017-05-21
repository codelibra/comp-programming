//shivi..coding is adictive!!
//print all anagrams together 
#include<shiviheaders.h>
using namespace std;
struct Node
{
	string str;
	int index;
};
bool criteria(Node a,Node b)
{
	return lexicographical_compare(a.str.begin(),a.str.end(),b.str.begin(),b.str.end());
}

int main()
{
		string arr[10];
		Node arr2[10];
		int N;
		cin>>N;
		
		for(int i=0;i<N;++i)
		{
		cin>>arr[i];
		arr2[i].str=arr[i];
		arr2[i].index=i;
		}
		
		for(int i=0;i<N;++i)
			sort(arr2[i].str.begin(),arr2[i].str.end());
		
		sort(arr2,arr2+N,criteria);
		cout<<endl;
		for(int i=0;i<N;++i)
		{
			cout<<arr[arr2[i].index]<<" ";
		}

}
