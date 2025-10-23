#include <iostream>
#include<bits/stdc++.h>
using namespace std;


bool canweplacecows(vector<int>arr,int distance,int k)
{  //Greedy Approach
  int cow_count = 1;  //Since one cow is already placed at first position so increasing count
  int c1 = arr[0];   //Put one cow in first stall
  for(int i=1; i<arr.size(); i++)
  {
    if((arr[i]-c1) >= distance)
    {
      c1= arr[i];
      cow_count++;
    }
  }
  if(cow_count >= k)
  {
    return true;
  }
  return false;
}

int aggresive_cows(vector<int>arr,int k)
{
  sort(arr.begin(),arr.end());   //sorting the vector
  int n = arr.size();
  int start = 1;
  int end = arr[n-1] - arr[0];
   int result =0;
  while(start <= end)
  { 
    int mid = (start+end)/2;
    
    if(canweplacecows(arr,mid,k)) 
    {
      result = mid;
      start = mid+1;
    }
    else
    {
      end = mid-1;           //If mid dist is 5 and if it is not possible then obviously value greater than it willnot be possible
    }
  }
  return result;
}


int main()
{
  vector<int>arr = {0,3,4,7,10,9};
  int k=4;
  cout<<aggresive_cows(arr,k);
}