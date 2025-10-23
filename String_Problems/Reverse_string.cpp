#include<bits/stdc++.h>
using namespace std;

string reverse_str(string str)
{
  int n = str.size();
  string result = "";
  for(int i=n-1; i>=0; i--)
  {
    result += str[i];
  }
  return result;
}

int main()
{
  string str = "abcd";
  
  cout<<reverse_str(str)<<endl;
}