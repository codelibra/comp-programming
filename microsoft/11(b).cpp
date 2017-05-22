//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/array-rotation/
#include<shiviheaders.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int d,n=sizeof(arr)/sizeof(int),temp,j,k;
	cin>>d;
	for(int i=0;i<gcd(d,n);++i)
	{
		temp=arr[i];
		j=i;
		while(1)
		{
			k=j+d;
			if(k>=n)
			k=k-n;
			
			if(k==i)
			break;
			
			arr[j]=arr[k];
			j=k;
		}
		arr[j]=temp;
	}
	for(int i=0;i<n;++i)
	cout<<arr[i]<<" ";
}
