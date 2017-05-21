//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;
int nextright[100000],nextleft[100000],sum[100000];
class Solution {
public:
        
        int trap(int A[], int n) 
        {
         if(n==0)   return 0;
         vector<int> vi;
         for(int i=0;i<n;++i)
         vi.push_back(A[i]);
         
         return maxArea(vi);
        }
        
	  int maxArea(vector<int> &height)
      {
      
      stack<int> st;
      int N=height.size();
      st.push(N-1);
      nextright[N-1]=-1;
      sum[0]=height[0];
      
      for(int i=1;i<N;++i)
      sum[i]=height[i]+sum[i-1];
      	
      
      for(int i=N-2;i>=0;--i)
      {
          if(height[i]<height[st.top()])
          {
                nextright[i]=st.top();
                st.push(i);
          }
          else
          {
              while(!st.empty() && height[i]>height[st.top()])
              st.pop();
              if(st.empty())
              {
                  st.push(i);
                  nextright[i]=-1;
              }
              else
              {
                  nextright[i]=st.top();
                  st.push(i);
              }
          }
          
      }
      
	 while(!st.empty())
     st.pop();
      
      
      st.push(0);
      nextleft[0]=-1;
      for(int i=1;i<N;++i)
      {
          if(height[i]<height[st.top()])
          {
                nextleft[i]=st.top();
                st.push(i);
          }
          else
          {
              while(!st.empty() && height[i]>height[st.top()])
              st.pop();
              if(st.empty())
              {
                  st.push(i);
                  nextleft[i]=-1;
              }
              else
              {
                  nextleft[i]=st.top();
                  st.push(i);
              }
          }
          
      }
      
      int area1=0,area2=0,i=0,j;
      
      while(i<N)
      {
		if(nextright[i]!=-1)
		{
			area1+=height[i]*(nextright[i]-i-1)-(sum[nextright[i]-1]-sum[i]);
			i=nextright[i];
     	}
     	else if(nextright[i]==-1 && i!=N-1)
     	{
			
			j=i+1;
			int prev;
	     	while(j<N)
			{
	     		if(nextleft[j]==i)
	     		prev=j;
	     		++j;
	     	}	
	     	--j;
	     	area1+=height[prev]*(prev-nextleft[prev]-1)-(sum[prev-1]-sum[nextleft[prev]]);
	     	i=prev;
	     }
	     else ++i;
      }
     
     return area1;
    }

};
int main()
{
	int heights[8];
	heights[0]=6;
	heights[1]=8;
	heights[2]=5;
	heights[3]=0;
	heights[4]=0;
	heights[5]=6;
	heights[6]=5;
	//heights[7]=5;
/*	heights.push_back(0);
	heights.push_back(1);
	/*heights.push_back(0);
	heights.push_back(1);
	heights.push_back(3);
	heights.push_back(2);
	heights.push_back(1);
	heights.push_back(2);
	heights.push_back(1);*/
	Solution s;
	cout<<s.trap(heights,7);
	//cout<<s.maxArea(k);
}