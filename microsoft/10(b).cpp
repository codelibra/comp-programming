//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/median-of-two-sorted-arrays/
#include<shiviheaders.h>
using namespace std;
int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45},n=sizeof(ar1)/sizeof(int);
    
    int lo=0,hi=n,j;
    
    bool ans=0;
    
    while(lo<hi)
    {
    	 cout<<lo<<" "<<hi<<endl;
	 int mid=(lo+hi)/2;
    	 if(mid>=n-1) {ans=1;lo=0;hi=n-1;mid=(lo+hi)/2;}
    	 
    	 j=n-mid-1;
    	 
	if(!ans)
    	{
	    	
	 if(ar1[mid]>=ar2[j] && ar1[mid]<ar2[j+1])
    	 {
 	  cout<<(ar1[mid]+ar2[j]) /2;
	   break; 	
    	 }
    	 
    	 else if(ar1[mid]>ar2[j] && ar1[mid]>ar2[j+1])
    	 hi=mid-1;
    	 
    	 else if(ar1[mid]<ar2[j] && ar1[mid]<ar2[j+1])
    	 lo=mid+1;
    	}
    	
    	else
    	{
	 
	 if(ar2[mid]>=ar2[j] && ar2[mid]<ar2[j+1])
    	 {
 	  cout<<(ar2[mid]+ar2[j]) /2;
	  break; 	
    	 }
    	 
    	 else if(ar2[mid]>ar2[j] && ar2[mid]>ar2[j+1])
    	 hi=mid-1;
    	 
    	 else if(ar2[mid]<ar2[j] && ar2[mid]<ar2[j+1])
    	 lo=mid+1;   	
	}
    }
    
}
