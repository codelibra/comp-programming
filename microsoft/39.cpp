//shivi..coding is adictive!!
#include<shiviheaders.h>
#define R 6
#define C 5
using namespace std;
int mini(int a, int b, int c)
{
  int m = a;
  if (m > b) 
    m = b;
  if (m > c) 
    m = c;
  return m;
}
int main()
{
	bool M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
                   
      bool S[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 0, 0, 0, 0}, 
                   {0, 0, 0, 0, 0},
                   {1, 0, 0, 0, 0},
                   {1, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0}};
	 
	 for(int i=1;i<R;++i)             
	 {
 		for(int j=1;j<C;++j)
 		{
			
			 if(M[i][j]==1)
			 {
				
				 S[i][j]=mini(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1;
			 }
			 else
			 S[i][j]=0;
			 
		 }
 	}
 	
 	 for(int i=0;i<R;++i)             
	 {
 		for(int j=0;j<C;++j)
 		{
		 cout<<S[i][j]<<" ";
		 }
		 cout<<endl;
	 }
}
