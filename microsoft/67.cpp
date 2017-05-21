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
		{1,0,0,0}
	};
	
	int row[R],col[R];
	
	for(int i=0;i<R;++i)
	{
		for(int j=0;j<R;++j)
		{
			if(M[i][j]==1)
			{
				row[i]=1;
				col[j]=1;
			}
		}
	}
	
	for(int i=0;i<R;++i)
	{
		if(row[i]==1)
		{
			for(int j=0;j<R;++j)
			M[i][j]=1;
		}
	}
	
	for(int i=0;i<R;++i)
	{
		if(col[i]==1)
		{
			for(int j=0;j<R;++j)
			M[j][i]=1;
		}
	}
	
	for(int i=0;i<R;++i)
	{
			for(int j=0;j<R;++j)
			cout<<M[i][j]<<" ";
			cout<<endl;
	}
}
