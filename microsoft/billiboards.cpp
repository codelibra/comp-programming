//shivi..coding is adictive!!
#include<stdio.h>
long long int arr[100001];
long long  int sum[100001];
long long  int including[100001],excluding[100001];
long long int maxim(long long int a,long long int b)
{if(a>b) return a;return b;}
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;++i)scanf("%lld",&arr[i]);
	
	sum[0]=arr[0];
	including[0]=sum[0];
	excluding[0]=sum[0];
	for(int i=1;i<K;++i)
	{
		sum[i]+=sum[i-1]+arr[i];
		including[i]=sum[i];
		excluding[i]=sum[i];
	}
	
 	long long int maxi=0,temp=0;
	for(int i=K;i<N;++i)
	{
		sum[i]+=sum[i-1]+arr[i];
		for(int j=1;j<=K;++j)
		{
			temp=sum[i]-sum[i-j];
			if(i-j-1>=0)
			temp+=including[i-j-1];
			if(temp>maxi)maxi=temp;
		}
		including[i]=maxi;
		excluding[i]=including[i-1];
	}
	printf("%lld",maxim(including[N-1],excluding[N-1]));
}
