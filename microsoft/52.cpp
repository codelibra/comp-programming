//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,k;
	cin>>N;
	int arr[100];
	for(int i=0;i<N;++i)cin>>arr[i];
	
	int Lmin[100],Rmax[100];
	Lmin[0]=arr[0];Rmax[N-1]=arr[N-1];
	
	for(int i=1;i<N;++i)
		Lmin[i]=min(Lmin[i-1],arr[i]);
		
	for(int i=N-2;i>=0;--i)
		Rmax[i]=max(Rmax[i+1],arr[i]);	
	
	int i=0,j=0,maxdiff=INT_MIN;
	while(i<N && j<N)	
	{
		if(Lmin[i]<Rmax[j])
		{
			if(maxdiff<j-i)
			maxdiff=j-i;
			
			++j;
		}
		else
		++i;
	}
	
	cout<<maxdiff<<endl;
}
