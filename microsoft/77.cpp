//shivi..coding is adictive!!
//print matrix in spiral form
#include<shiviheaders.h>
#define R 3
#define C 6
using namespace std;
int main()
{
	int mat[R][C] = 
	{ {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
    
    int a=0,b=R,c=0,d=C,i;
    //a start row
    //b end row
    //c start column
    //d end column
    
    while(a<b && c<d)
    {
    		for(i=c;i<d;++i)
    		cout<<mat[a][i]<<" ";
    		++a;
    		
    		for(i=a;i<b;++i)
    		cout<<mat[i][d-1]<<" ";
    		--d;
    		
    		if(a<b)
    		{
			for(i=d-1;i>=c;--i)
			cout<<mat[b-1][i]<<" ";
			--b;
          }
          
          if(c<d)
          {
          	for(i=b-1;i>=a;--i)
			cout<<mat[i][c]<<" ";
			++c;
          }
    }
    
    
}
