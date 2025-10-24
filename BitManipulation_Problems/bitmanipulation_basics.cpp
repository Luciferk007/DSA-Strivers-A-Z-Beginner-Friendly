#include<bits/stdc++.h>
using namespace std;


//Bit Manipulation

void dectobinary(int n)
{
  string rem = "";
  int val;
  while(n>0)
  {
    val = n%2;
    n = n/2;
    rem +=to_string(val);
  }
  reverse(rem.begin(),rem.end());
  cout<<rem<<endl;
}

void bintodec(int bin)
{
  int result =0;
  int i=0;
  while(bin> 0)
  {
    result += (bin%10) * pow(2,i);
    bin = bin/10;
    i++;
  }
  cout<<result<<endl;
}
bool check_if_kth_bit_set(int bin, int k)
{
  if((bin & (1<<(k-1))) != 0)   // dont compare with ==1 becauese for k=3 1<<2 = 4 and 5&4=4  not 1 so it will unessecryil return false
  {
    return true;
  }
  else
  {
    return false;
  }
}

void check_odd_or_not(int bin)
{
  if((bin &1) == 1)
  {
    cout<<"Odd"<<endl;
  }
  else
  {
    cout<<"Even"<<endl;
  }
}

void check_power_of_two(int x)
{
  if((x&(x-1)) == 0)
  {
    cout<<"Is a Power of 2"<<endl;
  }
  else
  {
    cout<<"Not a Power of 2"<<endl;
  }
}

void count_set_bits(int x)
{
  int count =0;
  while(x)
  {
    x = x&(x-1);
    count++;
  }
  cout<<count<<endl;
}

void swap(int a, int b)
{
  a = a^b;
  b = a^b;
  a = a^b;
  cout<<"a ="<<a<<" b= "<<b<<endl;
}
void setrightmostunsetbit(int n)
{
  cout<<"Before Setting: ";
  dectobinary(n);
  n = n|(n+1);
  cout<<"After Setting: ";
  dectobinary(n);
}

int main()
{
  int n = 13;
  dectobinary(n);
  bintodec(1101);
  
  if(check_if_kth_bit_set(5,3) == true)
  {
    cout<<"Is set"<<endl;
  }
  else
  {
    cout<<"Not set"<<endl;
  }
  check_odd_or_not(6);
  check_power_of_two(5);
  count_set_bits(5);
  swap(5,6);
  setrightmostunsetbit(n);
}