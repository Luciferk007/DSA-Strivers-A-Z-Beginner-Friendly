#include<bits/stdc++.h>
using namespace std;

//No of flips required to convert start to goal
int find_no_of_flips(int start, int goal)
{
  int result = start ^ goal;
  int count =0;
  while(result >0)
  {
    result = result&(result-1);
    count++;
  }
  return count;
}

int main()
{
  int start = 3; int goal = 4;
  cout<<find_no_of_flips(start, goal)<<endl;
}