#include<bits/stdc++.h>
using namespace std;

//Using counter-->O(1) timecomplexity: Most Effiecient
string Remove_outermost_valid_paranthesis(string str)
{
  int depth =0;
  string result = "";
  for(char c: str)
  {
    if(c == '(')
    {
      if(depth >0)
      result +=c;
      depth++;
    }
    else
    {
      depth--;
      if(depth >0)
      result +=c;
    }
  }
  return result;
}

//Using Stack-->O(n)

string stack_remove_outermost_valid_parenthesis(string str)
{
  stack<char>st;
  string result = "";
  for(char c: str)
  {
    if(c == '(')  //Remvoe (
    {
      if(!st.empty())
      result += c;   //Add ( avoiding outermost (
      st.push(c);
    }
    else
    {
      st.pop();      //Removing outermost )
      if(!st.empty())  
      result +=c;    //Adding rest of them
    }
  }
  return result;
}

int main()
{
  string str = "((()))";
  
  cout<<Remove_outermost_valid_paranthesis(str);
  cout<<endl;
  cout<<stack_remove_outermost_valid_parenthesis(str);
}