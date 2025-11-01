#include<bits/stdc++.h>
using namespace std;

// bool is_prime(int digit)
// {
//   if(digit <= 1)
//   {
//     return false;
//   }
//   if(digit == 2)
//   {
//     return false;
//   }
//   for(int i=2; i*i <= digit; i++)
//   {
//     if(digit %i == 0)
//     return false;
//   }
//   return true;
// }

const int MOD = 1e9 + 7;

int goodfxn(int index)
{
  int result=1;
  int multiplier;
  if (index <= 0)  // base case
        return 1;
        
  if(index > 0)
  {
    if((index-1)%2 == 0)
    {
      multiplier =5;
    }
    else 
    {
      multiplier =4;
    }
  result = (multiplier * goodfxn(index-1))% MOD;
  }
  return result;
}


int main()
{
    int index = 3;
    cout << goodfxn(index) << endl;
    return 0;
}