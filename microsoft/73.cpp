//shivi..coding is adictive!!
//transpose of a square matrix
#include<shiviheaders.h>
using namespace std;
//transpose of aa square matrix can be done by mirroring across it's diagonals!!!!
int main()
{
	int arr[4][4]=
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			if(i>j)
			{
				swap(arr[i][j],arr[j][i]);
			}
		}
	}
	for(int i=0;i<4;++i)
	{
		for(int j=0;j<4;++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
