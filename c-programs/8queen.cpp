//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
bool isSafe(int x,int y,int solution[8][8])
{
	for(int i=0;i<8;++i)
	if(solution[x][i]==1) return 0;
	
	for(int i=0;i<8;++i)
	if(solution[i][y]==1) return 0;
	
	int i=x,j=y;
	while(i>=0 && j>=0)
	{
		if(solution[i][j]==1)
		return 0;
		--i;
		--j;
	}
	
	i=x,j=y;
	while(i>=0 && j<8)
	{
		if(solution[i][j]==1)
		return 0;
		--i;
		++j;
	}
	
	return 1;
}

bool PlaceQueen(int row,int solution[8][8])
{
	if(row>7) return 1;
	
	for(int k=0;k<8;++k)
	{
		if(isSafe(row,k,solution))
		{
			solution[row][k]=1;
			if(PlaceQueen(row+1,solution))
			return 1;
			solution[row][k]=0;
		}
	}
	return 0;
}

void Nqueens()
{
	int Solution[8][8];
	for(int i=0;i<8;++i)
		for(int j=0;j<8;++j)
			Solution[i][j]=0;
			
	
	PlaceQueen(0,Solution);
	for(int i=0;i<8;++i)
	{
		for(int j=0;j<8;++j)
		{
			cout<<Solution[i][j]<<" ";
		}
		cout<<endl;
	}
	
}

int main()
{
	Nqueens();
}
