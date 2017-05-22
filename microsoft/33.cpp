#include <stdio.h>
#define CHAR_BIT 8
#include<shiviheaders.h>
using namespace std; 
/* This function will return absoulte value of n*/
unsigned int getAbs(int n)
{
  int const mask = n >> (sizeof(int) * CHAR_BIT - 1);
  //if postivie number this will give 0000000....
  //if negetive number it will give 111111......
  return ((n + mask) ^ mask);
}
 
/* Driver program to test above function */
int main()
{
  int n = -6;
  printf("Absoute value of %d is %u", n, getAbs(n));
 
  getchar();
  return 0;
}