//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int arr[3][5]=
{
	{1,3,2,6,8},
	{-9,2,1,-1,2},
	{1,5,0,1,9},
};
int dp[100][100];

void Preprocess()
{
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<5;++j)
			dp[i][j]=1;
	}
	
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<5;++j)
		{
			if(i==0 && j==0)
			continue;
			
			if(i==0 && abs(arr[i][j-1]-arr[i][j])<=1 && dp[i][j]<dp[i][j-1]+1)
			{
				dp[i][j]=1+dp[i][j-1];
				continue;
			}
			
			if(j==0 && abs(arr[i-1][j]-arr[i][j])<=1 && dp[i][j]<dp[i-1][j]+1)
			{
				dp[i][j]=1+dp[i-1][j];
				continue;
			}
			
			if(abs(arr[i][j-1]-arr[i][j])<=1 && dp[i][j]<dp[i][j-1]+1)
			dp[i][j]=1+dp[i][j-1];
			
			if(abs(arr[i-1][j]-arr[i][j])<=1 && dp[i][j]<dp[i-1][j]+1)
			dp[i][j]=1+dp[i-1][j];
			
		}
	}
	
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<5;++j)
		{
			cout<<dp[i][j]<<" ";
		}
			cout<<endl;
	}
	
}
int maxi;
void print(int data[],int i,int j,int maxval,int index)
{
	//cout<<index<<endl;
	if(index<0) return;
	
	if(index==1)
	{
		data[index]=arr[i][j];
		for(int i=1;i<=maxi;++i)
		cout<<data[i]<<" ";
		cout<<endl;
		return;
	}
	
	if(i-1>=0 && dp[i-1][j]==maxval-1 && abs(arr[i-1][j]-arr[i][j])<=1)
	{
		data[index]=arr[i][j];
		print(data,i-1,j,maxval-1,index-1);
	}
	
	if(j-1>=0 && dp[i][j-1]==maxval-1 && abs(arr[i][j-1]-arr[i][j])<=1)
	{
		data[index]=arr[i][j];
		print(data,i,j-1,maxval-1,index-1);
	}
	
}

void printsnake()
{
	int maxval=0;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<5;++j)
			{
				if(dp[i][j]>maxval)
				maxval=dp[i][j];
			}
	}
	int data[100];
	maxi=maxval;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<5;++j)
			{
				if(dp[i][j]==maxval)
				{
					print(data,i,j,maxval,maxval);
				}
			}
	}
}

int main()
{
	Preprocess();
	printsnake();
}
