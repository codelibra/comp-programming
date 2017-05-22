//shivi..coding is adictive!!
//print boolean matrix
#include<shiviheaders.h>
#define R 4
#define C 4
using namespace std;
int main()
{
	int M[R][R]=
	{
		{1,0,0,1},
		{0,0,1,0},
		{0,0,0,0},
		{0,0,0,0}
	};
	
	//int row[R],col[R];
	int rowflag=0,colflag=0;
	
	for(int i=0;i<R;++i)
	{
		if(M[0][i]==1) colflag=1;
		if(M[i][0]==1) rowflag=1;
	}
	
	for(int i=1;i<R;++i)
	{
		for(int j=1;j<R;++j)
		{
			if(M[i][j]==1)
			{
				M[0][j]=1;
				M[i][0]=1;
			}
		}
	}
	
	
	
	for(int i=1;i<R;++i)
	{
		if(M[i][0]==1)
		{
			for(int j=0;j<R;++j)
			M[i][j]=1;
		}
	}
	
	
	for(int i=0;i<R;++i)
	{
		if(M[0][i]==1)
		{
			for(int j=0;j<R;++j)
			M[j][i]=1;
		}
	}
	if(rowflag)
	{
			for(int j=0;j<R;++j)
			M[j][0]=1;
	}
	
	if(colflag)
	{
			for(int j=0;j<R;++j)
			M[0][j]=1;
	}
	
	for(int i=0;i<R;++i)
	{
			for(int j=0;j<R;++j)
			cout<<M[i][j]<<" ";
			cout<<endl;
	}
}
