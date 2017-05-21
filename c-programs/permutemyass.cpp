#include<shiviheaders.h>
using namespace std;
bool Find(string str,int i,int j)
{
	if(i==j) return 1;
	
	for(int k=i;k<j;k++)
	if(str[k]==str[j]) return 0;
	
	return 1;
}

void Permute(string str,int i,int N)
{
	if(i>=N){cout<<str<<endl;return;}
	
	for(int j=i;j<=N;++j)
	{
		if(Find(str,i,j))
		{
		swap(str[i],str[j]);
		Permute(str,i+1,N);
		swap(str[i],str[j]);
		}
	}
}

int main()
{
	Permute("ABAA",0,3);
}
