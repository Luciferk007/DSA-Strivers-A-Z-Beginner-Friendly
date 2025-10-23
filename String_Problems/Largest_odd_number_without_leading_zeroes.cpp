#include<bits/stdc++.h>
using namespace std;

string largest_odd_number_without_leading_zero(string str)
{
  int n = str.size();
  string result = "";
  //First of all finding the last odd index
  int last_odd_index =0;
  int first_index =0;
  for(int i=n-1; i>=0; i--)
  {
    if((str[i] -'0')%2 == 0)     //If even
    {
      str.erase(i,1);
    }
    else
    {
      last_odd_index = i;
      break;
    }
  }
  //Checking if leading zero is there or not: 
  while(first_index<=last_odd_index)
  {
    if((str[first_index] - '0') != 0)
    {
      break;
    }
    else
    {
      str.erase(first_index,1);
    }
  }
  return str;
  
}

int main()
{
  string str = "0000214638888";
  
  cout<<largest_odd_number_without_leading_zero(str);
}