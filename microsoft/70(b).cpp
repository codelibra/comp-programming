//shivi..coding is adictive!!
#include<shiviheaders.h>
#define R 4
#define C 5
using namespace std;
int top,bottom;
int temp[C];
int Kadane()
{
	int max_till_nw=-100000,max_so_far=-100000;
	
	for(int i=0;i<R;++i)
	{
		max_so_far=max_so_far+temp[i];
		if(max_so_far<temp[i])
		{
			top=i;
			max_so_far=temp[i];
		}
		
		if(max_till_nw<max_so_far)
		{
			max_till_nw=max_so_far;
			bottom=i;
		}
		
	}
	
	return max_till_nw;
}

int main()
{
	int arr[R][C]=
	{
		{1,2,-1,-4,-20},
		{-8,-3,4,2,1},
		{3,8,10,1,3},
		{-4,-1,1,7,-6},
	};
	
	int leftcol=0,rightcol=1,sum,finalleft,finalright,finaltop,finalbottom,maxsum=INT_MIN;
	
	for(leftcol=0;leftcol<C;++leftcol)
	{
		fill_n(temp,R,0);
		for(rightcol=leftcol;rightcol<C;++rightcol)
		{
			for(int i=0;i<R;++i)
			temp[i]+=arr[i][rightcol];
			
			sum=Kadane();
			if(sum>maxsum)
			{
				maxsum=sum;
				finalleft=leftcol;
				finalright=rightcol;
				finaltop=top;
				finalbottom=bottom;
			}
		}
	}
	
	cout<<maxsum<<" "<<finaltop<<" "<<finalleft<<" "<<" "<<finalright<<" "<<finalbottom<<" "<<endl;
}

