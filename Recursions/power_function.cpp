#include <bits/stdc++.h>
using namespace std;


double power_fxn(double x, int n)
{
  double result =1.0;
  if(n>0)
  {
    result = x*power_fxn(x,n-1);
  }
 return result;
}

double power_efficent_fxn(double x, long long pow)
{
  double result = 1.0;
  long long n = pow;
  
  if (n<0) n = abs(n);
  while(n>0)
  {
    if(n%2 != 0)     //odd power
    {
      result = result*x;
      n=n-1;
    }
    else
    {
      x = x * x;
      n = n/2;
    }
  }
  if(pow < 0)
  {
    result = (double) 1.0 / (double) result;
  }
  return result;
}

int main()
{
  cout<<power_fxn(2.3,100)<<endl;
  cout<<power_efficent_fxn(2.3,100);
}