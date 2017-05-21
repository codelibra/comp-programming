//shivi..coding is adictive!!
#include<shiviheaders.h>
#include <vector>
using namespace std;
int main()
{
	fstream fin,fin2;
	string str1;
	fin.open("C:/Users/shivendra/Desktop/Micro.html",ios::out);
	
		
	
	cout<<"Please Enter Heading\n :";
	cin>>str1;
	
	int N;
	cout<<"Enter Number Of CheckBoxes\n :";
	cin>>N;
	fin<<"<h1>"<<str1<<"</h1>\n";
	cout<<"Enter the values\n";
	fin<<"<form>\n";
	for(int i=0;i<N;++i)
	{
		cin>>str1;
		fin<<"<input type=\"checkbox\" name=\"vehicle\" value=\"Bike\">"<<str1<<"<br>\n";
	}
	fin<<"</form>\n";
	
}
