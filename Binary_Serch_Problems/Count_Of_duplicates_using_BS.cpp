#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int firstoccurence(vector<int>&arr, int target)
{
  int n = arr.size();
  int start =0;
  int end = n-1;
  int count =0;
  int first_index = 0;
  while(start<=end)
  {
    int mid = (start+end)/2;
    if(arr[mid] == target)
    {
      first_index =mid;
      end = mid -1;
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
  return first_index;
}

int lastoccurence(vector<int>&arr, int target)
{
  int n = arr.size();
  int start =0;
  int end = n-1;
  int count =0;
  int last_index = 0;

  while(start <=end)
  {
    int mid = (start + end)/2;
    
    if(arr[mid] == target)
    {
      last_index = mid;
      start = mid+1;
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
  return last_index;
}

int countofoccurence(vector<int>&arr, int target)
{
  int result1 = lastoccurence(arr,target);
  int result2 = firstoccurence(arr,target);
  int result = result1 - result2;
  if(result >0)
  {
    return result+1;
  }
  return -1;
}



int main()
{
  vector<int>arr = {3,4,13,13,13,20,40};
  int target = 13;
  cout<<countofoccurence(arr,target);
}