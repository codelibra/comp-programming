//shivi..coding is adictive!!
//longest common substring
#include<shiviheaders.h>
using namespace std;
int arr[100][100];
int main()
{
	int ans=0;
	string a,b;
	cin>>a>>b;
	
	for(int i=0;i<=a.length();++i)
	{
		for(int j=0;j<=b.length();++j)
		{
			if(i==0 || j==0)
			arr[i][j]=0;
			
			else if(a[i-1]==b[j-1])
			{
				arr[i][j]=arr[i-1][j-1]+1;
			}
			else
			{
				arr[i][j]=0;
			}
			
			for(int k=0;k<8;++k)
			{
				for(int m=0;m<8;++m)
				{
					cout<<arr[k][m]<<" ";
				}
				cout<<endl;
			}
			getch();
			cout<<endl;
		}
	}
	cout<<ans;
	
}
 