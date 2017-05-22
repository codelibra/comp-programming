//shivi..coding is adictive!!
//Search in a row wise and column wise sorted matrix
#include<shiviheaders.h>
using namespace std;
int main()
{
	int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
      int N;
	 cin>>N;
	 
	 int i=0,j=3;
	 while(i<4 && j<4 && i>=0 && j>=0)
	 {
 		if(mat[i][j]==N)
 		{cout<<"found";break;}
 		else if(N>mat[i][j])
 		++i;x
 		else 
 		--j;
 	}
}
