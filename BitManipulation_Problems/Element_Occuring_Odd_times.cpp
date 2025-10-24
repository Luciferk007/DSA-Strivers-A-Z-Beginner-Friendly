#include<bits/stdc++.h>
using namespace std;


int find_no_occuring_odd_times(vector<int>arr)
{
  int result=0;
  for(int x: arr)
  {
    result ^=x;
  }
  return result;
}

int main()
{
  vector<int>arr = {1, 2, 2, 4, 3, 1, 4};
  cout<<find_no_occuring_odd_times(arr)<<endl;
}