//shivi..coding is adictive!!
//Next Greater Element
#include<shiviheaders.h>
using namespace std;
int main()
{
	stack<int> s;
	int N,arr[100];
	cin>>N;
	for(int i=0;i<N;++i)cin>>arr[i];
	int i=1,ele;
	s.push(arr[0]);
	
	while(!s.empty())
	{
		if(i>=N) break;
		ele=arr[i++];
		
		int top=s.top();
		while(ele>top)
		{
			cout<<top<<" "<<ele<<endl;
			s.pop();
			if(s.empty() == true) break;
			top=s.top();
		}
		
		if((!s.empty() && ele<s.top()) || s.empty())
		s.push(ele);
	}
}
