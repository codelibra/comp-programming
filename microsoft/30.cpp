//shivi..coding is adictive!!
//http://www.geeksforgeeks.org/next-higher-number-with-same-number-of-set-bits/
#include<shiviheaders.h>
using namespace std;
int main()
{
	int N,setpatern,rgtsft;
	cin>>N;
	
	//righmost
	int righmost=N&(-N);
	
	//shift set left
	rgtsft=N+righmost;
	
	//isolate set
	setpatern=rgtsft^N;	
	
	//rightshift set
	setpatern=setpatern/righmost;
	
	//remove  extra
	setpatern=setpatern>>2;
	
	cout<<(rgtsft+setpatern)<<endl;
	
	
	
	
	
}
