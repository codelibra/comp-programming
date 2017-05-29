#include<string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a1, string b1) {
        int a,b,c,d;
        sscanf(a1.c_str(),"%d+%di",&a,&b);
        sscanf(b1.c_str(),"%d+%di",&c,&d);
        return to_string(a*c-b*d) + "+" + to_string(a*d+b*c) + "i";
    }
};

/*
        int ra, ia, rb, ib;
        char buff;
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
*/
