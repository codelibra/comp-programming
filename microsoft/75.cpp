//shivi..coding is adictive!!
//median of a stream of integers
#include<shiviheaders.h>
using namespace std;
int main()
{
	priority_queue<int> maxpq;
	priority_queue<int,vector<int>,greater<int> > minpq;
	
	int x;
	while(1)
	{
		cin>>x;
		if(maxpq.size()==0)
		{maxpq.push(x);cout<<x<<endl;}
		
		else if(maxpq.size()>minpq.size())
		{
			int k=maxpq.top();
			
			if(x>k) minpq.push(x);
			else 
			{
				int p=maxpq.top();
				maxpq.pop();
				minpq.push(p);
				maxpq.push(x);
			}
			cout<<(maxpq.top()+minpq.top())/2<<endl;
		}
		else
		{
			int k=minpq.top();
			
			if(x<k) maxpq.push(x);
			else 
			{
				int p=minpq.top();
				minpq.pop();
				maxpq.push(p);
				minpq.push(x);
			}
			cout<<maxpq.top()<<endl;
		}
	}
}
