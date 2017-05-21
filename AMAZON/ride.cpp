/*
ID: shiven2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int value(string str)
{
	int ans=1;
	for(int i=0;i<str.length();++i)
	{
		ans=(ans*(str[i]-'A'+1));
		ans=ans%47;
	}
	return ans;
}
int main() 
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    fin >> a >> b;
    int ans1,ans2;
    ans1=value(a);
    ans2=value(b);
    if(ans1==ans2)
    fout<<"GO\n";
    else
    fout<<"STAY\n";
    return 0;
}