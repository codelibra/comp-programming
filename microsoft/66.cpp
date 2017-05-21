//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
#include<shiviheaders.h>
using namespace std;

bool criteria(int a,int b)
{
	int p=a,q=b,count1=0,count2=0;
	while(p)
	{
		p/=10;
		++count1;
	}
	
	while(q)
	{
		q/=10;
		++count2;
	}
	
	if(b+a*pow(10.0,count2)>a+b*pow(10.0,count1))
	return 1;
	else
	return 0;
	
}

int main()
{
	int i,N,arr[100];
	cin>>N;
	for(int i=0;i<N;++i)cin>>arr[i];
	
	sort(arr,arr+N,criteria);
	
	for(int i=0;i<N;++i)cout<<arr[i];
}
