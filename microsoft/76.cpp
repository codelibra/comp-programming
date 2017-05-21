//shivi..coding is adictive!!
//median of two sorted arrays
#include<shiviheaders.h>
using namespace std;
int median(int arr[],int n)
{
	if(n%2==0)
	return (arr[n/2]+arr[n/2-1])/2;
	else
	return arr[n/2];
}

int GetMedian(int arr1[],int arr2[],int n)
{
	if(n==0)
	return -1;
	
	if(n==1)
	return arr1[n];
		
	if(n==2)
	return  (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;
	
	int m1,m2;
	m1=median(arr1,n);
	m2=median(arr2,n);
	
	if(m1==m2)
	return m1;
	
	if(m1>m2)
	{
		if(n%2==0)
		return GetMedian(arr1,arr2+n/2-1,n-n/2+1);
		else
		return GetMedian(arr1,arr2+n/2,n/2);
	}
	else
	{
		if(n%2==0)
		return GetMedian(arr1+n/2-1,arr2,n-n/2+1);
		else
		return GetMedian(arr1+n/2,arr2,n/2);
	}
	
}

int main()
{
	
}
