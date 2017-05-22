//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
struct Node
{
	int distance;
	int petrol;
};


int main()
{
	int N;
	cin>>N;
	Node arr[100];
	for(int i=0;i<N;++i)
	cin>>arr[i].distance>>arr[i].petrol;
	
	int start=0,end=start+1,petrolleft=arr[0].distance-arr[0].petrol,currentpump;
	
	while(end!=start || petrolleft<0)
	{
		while(petrolleft<0 && end!=start)
		{
			petrolleft-=arr[start].petrol-arr[start].distance;
			++start;
			start%=N;
			if(start==0) 
			{
				cout<<-1;
				break;
			}
		}
		
		petrolleft+=arr[end].petrol-arr[end].distance;
		end++;
		end%=N;
	}
	
	cout<<start;
	
}
