#include<bits/stdc++.h>
using namespace std;


//Bit Manipulation

void dectobinary(int n)
{
  string rem = "";
  int val;
  while(n>0)
  {
    val = n%2;
    n = n/2;
    rem +=to_string(val);
  }
  reverse(rem.begin(),rem.end());
  cout<<rem<<endl;
}

void bintodec(int bin)
{
  int result =0;
  int i=0;
  while(bin> 0)
  {
    result += (bin%10) * pow(2,i);
    bin = bin/10;
    i++;
  }
  cout<<result;
}


int main()
{
  int n = 13;
  dectobinary(n);
  bintodec(1101);
}