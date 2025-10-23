#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int koko_eating_banana(vector<int>arr,int h)
{
  int start = 1;
  int end = *max_element(arr.begin(),arr.end());
  int result =0;
  while(start <= end)
  {
    long long hours = 0;
    int mid = (start+end)/2;
    for(int i=0; i<arr.size(); i++)
    {
      hours += ceil((double)arr[i]/mid);
    }
    if(hours <= h)
    {
      result = mid;
      end = mid -1;
    }
    else
    {
      start = mid+1;
    }
  }
  return result;
}


int main()
{
  vector<int>arr = {25, 12, 8, 14, 19};
  int h=5;
  cout<<koko_eating_banana(arr,h);
}