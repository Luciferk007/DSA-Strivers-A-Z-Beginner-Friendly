#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>&arr)
{
  int n = arr.size();
  for(int i=0; i<n; i++)
  {
    int min_v = i;
    for(int j=i+1; j<n; j++)
    {
      if(arr[min_v] > arr[j])
      {
        min_v = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min_v];
    arr[min_v] = temp;
    
  }
  cout<<endl;
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void insertion_sort(vector<int>&arr)
{
  int n = arr.size();
  for(int i=0; i<n; i++)
  {
    for(int j=i+1; j<n; j++)
    {
      if(arr[i] > arr[j])
      {
        swap(arr[i],arr[j]);
      }
    }
  }
}

void bubble_sort(vector<int>&arr)
{
  int n = arr.size();
  for(int i=n-1; i>0; i--)
  {
    for(int j=0; j<=i-1; j++)
    {
      if(arr[i] < arr[j])
      {
        swap(arr[i],arr[j]);
      }
    }
  }
  
}

void print_array(vector<int>arr)
{
  int n = arr.size();
  for(int i=0; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
}

int main()
{
  vector<int>arr = {4,5,6,2,3,7,1};
  print_array(arr);
  cout<<endl;
  //bubble_sort(arr);
  insertion_sort(arr);
  //selection_sort(arr);
  print_array(arr);
  
}