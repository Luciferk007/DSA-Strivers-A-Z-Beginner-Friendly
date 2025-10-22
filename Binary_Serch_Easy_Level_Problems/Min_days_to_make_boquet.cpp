#include <iostream>
#include<bits/stdc++.h>
using namespace std;


bool canmakeboquet(vector<int>arr,int day, int m,int k)
{
  int consecutive_roses =0;
  int bouquet_cnt =0;
  for(int i=0; i<arr.size();i++)
  {
  
  if(arr[i] <=day)
  {
    consecutive_roses++;
    if(consecutive_roses == k)
    {
      bouquet_cnt++;
      consecutive_roses =0;  //reset after creating a boquet
    }
  }
  
  else
  {
      consecutive_roses =0;  //reset because adjacency is broken
  }
  
  }
  
  if(bouquet_cnt >= m)
  {
    return true;
  }
  return false;
}

int max_boquet(vector<int>arr,int m,int k)
{
  int start = *min_element(arr.begin(),arr.end());
  int end = *max_element(arr.begin(),arr.end());
  int result =0;
  while(start <= end)
  { 
    int mid = (start+end)/2;
    
    if(canmakeboquet(arr,mid,m,k)) 
    {
      result = mid;
      end = mid-1;
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
  vector<int>arr = {7, 7, 7, 7, 13, 11, 12, 7};
  int m=2; int k=3;
  cout<<max_boquet(arr,m,k);
}