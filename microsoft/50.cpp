//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/find-the-minimum-distance-between-two-numbers/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int arr[100];
	for(int i=0;i<N;++i)cin>>arr[i];
	
	int min_dist=INT_MAX,prev,x,y;
	cin>>x>>y;
	for(int i=0;i<N;++i)
	{
		if(arr[i]==x || arr[i]==y)
		{
			prev=i;
			break;
		}
	}
	for(int i=prev+1;i<N;++i)
	{
		if(arr[i]==x || arr[i]==y)
		{
			if(arr[i]!=arr[prev] && i-prev<min_dist)
			{
				min_dist=i-prev;
				prev=i;
			}
			else
			prev=i;
		}
	}
	cout<<min_dist<<endl;
}
