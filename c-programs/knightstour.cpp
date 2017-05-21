//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;

bool isSafe(int x,int y,int solution[][8])
{
	if(x>=0 && y>=0 && solution[x][y]==-1)
	return 1;
	else
	return 0;
}

bool KnightSolution(int i,int j,int moves,int solution[][8],int x[],int y[])
{
	if(moves==8*8)
	return 1;
	
	for(int p=0;p<8;++p)
	{
		int nextx=i+x[p];
		int nexty=j+y[p];
		if(isSafe(nextx,nexty,solution))
		{
			solution[nextx][nexty]=moves;
			if(KnightSolution(nextx,nexty,moves+1,solution,x,y)==1)
			return 1;
			else
			solution[nextx][nexty]=-1;
		}
	}
	
	return 0;
}

void Print(int solution[][8])
{
	for(int i=0;i<8;++i)
	{
		for(int j=0;j<8;++j)
			cout<<solution[i][j]<<" ";
		cout<<endl;
	}
}

void KnightsTour()
{
	int solution[8][8],move=1;
	for(int i=0;i<8;++i)
		for(int j=0;j<8;++j)
			solution[i][j]=-1;
	
	solution[0][0]=0;
	
	int x[]={  2, 1, -1, -2, -2, -1,  1,  2 };
	int y[]={  1, 2,  2,  1, -1, -2, -2, -1 };
	KnightSolution(0,0,move,solution,x,y);
	Print(solution);
}
int main()
{
	KnightsTour();
}
