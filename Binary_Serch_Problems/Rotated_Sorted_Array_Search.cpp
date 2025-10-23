#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int rotatedsorted1(vector<int>arr, int target)
{
  int start =0; int end = arr.size()-1;
  int ans=0;
  while(start <=end)
  {
    int mid = (start+end)/2;
    if(arr[mid] == target)
    {
      ans = mid;
      return ans;
    }
    else if(arr[start] <= arr[mid])  //Check Left half is sorted`
    {
      if(arr[start] <= target && arr[mid] >= target)
      {
        end = mid -1;
      }
      else
      {
        start = mid+1;
      }
    }
    else if(arr[end] > arr[mid])  //Right Half Is Sorted
    {
      if(arr[mid] <=target && arr[end] >= target)
      {
        
        start = mid+1;
      }
      else
      {
        end = mid -1;
      }
      
    }
    else
    {
      ans = -1;
    }
  }
  return ans;
}



int main()
{
  vector<int>arr = {4,5,6,7,0,1,2,3};
  int target = 0;
  cout<<rotatedsorted1(arr,target);
}