#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int capacity_of_ship(vector<int>arr,int d)
{
  int start = *max_element(arr.begin(),arr.end());;
  int end = accumulate(arr.begin(),arr.end(),0);  //sum of all the weights in array
  int result =0;
  while(start <= end)
  { 
    int load =0;
    int days = 1;
    
    int mid = (start+end)/2;
    for(int i=0; i<arr.size(); i++)
    {
      if(mid >= arr[i]+load)
      {
        load += arr[i];
      }
      else
      {
        days++;
        load  = arr[i];
      }
    }
    if(days <= d)
    {
      result = mid;
      end = mid -1;
    }
    else if(days >= d)
    {
      start = mid+1;
    }
  }
  return result;
}


int main()
{
  vector<int>arr = {7,2,5,8};
  int d=4;
  cout<<capacity_of_ship(arr,d);
}