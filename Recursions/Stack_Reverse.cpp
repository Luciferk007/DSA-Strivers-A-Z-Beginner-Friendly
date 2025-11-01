#include<bits/stdc++.h>
using namespace std;

void recursion_stack_reverse(stack<int>&s,int n)
{
    if(n !=0 && !s.empty())
    {
      cout<<s.top()<<",";
      s.pop();
      recursion_stack_reverse(s,n-1);
    }
}

void insert_element(stack<int>&s,int value)
{
  s.push(value);
}


int main()
{
    stack<int>s;
    insert_element(s,1);
    insert_element(s,2);
    insert_element(s,3);
    insert_element(s,4);
    int n = s.size();
    recursion_stack_reverse(s,n);
    return 0;
}