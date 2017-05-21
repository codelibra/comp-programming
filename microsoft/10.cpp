//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/median-of-two-sorted-arrays/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
    
    int a=sizeof(ar1)/sizeof(int),b=sizeof(ar2)/sizeof(int),n=(a+b)/2,p=0,q=0,k=0,ele;
    
    for(int i=0;i<n;++i)
    {
    		if(ar1[p]<ar2[q])
		ele=ar1[p++];	
    		else
    		ele=ar2[q++];	
    		
    		++k;
    		if(k==n)
    		{
		cout<<ele;
		break;    	
		}
    }
}
