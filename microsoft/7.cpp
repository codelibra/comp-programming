//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/merge-one-array-of-size-n-into-another-one-of-size-mn/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int M[]={2, 8, -1,-1, -1, 13, -1, 15, 20};
	int N[]={5, 7, 9, 25};
	int k=sizeof(M)/sizeof(int)-1,p=sizeof(M)/sizeof(int)-1,q=0;
	
	for(int i=p;i>=0;--i)	
	if(M[i]!=-1)M[k--]=M[i];
	
	p=k+1;
	for(int i=0;i<sizeof(M)/sizeof(int);++i)
	{
		if(M[p]<N[q])
		{M[i]=M[p];++p;}
		else
		{M[i]=N[q];++q;}
	}
	for(int i=0;i<sizeof(M)/sizeof(int);++i)
	cout<<M[i]<<" ";
	
}
