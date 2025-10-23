#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void floorandceil(vector<int>arr, int target)
{
  int n = arr.size();
  int start =0;
  int end = n-1;
  int floor_value =0;
  int ceil_value =0;
  //ceil_value
  while(start <=end)
  {
    int mid = (start + end)/2;
    if(arr[mid] == target)
    {
      ceil_value = arr[mid];
      break;
    }
    else if(arr[mid] > target)
    {
      end = mid -1;
    }
    else
    {
      start = mid+1;
    }
  }
  //Floor Value
  while(start <=end)
  {
    int mid = (start + end)/2;
    if(arr[mid] == target)
    {
      floor_value = arr[mid];
      break;
    }
    else if(arr[mid] < target)
    {
      
      start = mid+1;
    }
    else
    {
      end =mid-1;
    }
  }
  
  cout<<"floor_value: "<<floor_value <<" ceil_value: "<<ceil_value<<endl;
}

int main()
{
  vector<int>arr = {3, 4, 4, 7, 8, 10};
  int target = 8;
  floorandceil(arr,target);
}