#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int lastoccurence(vector<int>arr, int target)
{
  int n = arr.size();
  int start =0;
  int end = n-1;
  int result =-1;
  while(start <=end)
  {
    int mid = (start + end)/2;
    
    if(arr[mid] == target)
    {
      start = mid+1;
      result = mid;
    }
    else if(arr[mid]<target)
    {
      start = mid+1;
    }
    else
    {
      end = mid -1;
    }
  }
  
  return result;
}



int main()
{
  vector<int>arr = {3,4,13,13,13,20,40};
  int target = 40;
  cout<<lastoccurence(arr,target);
}