#include<bits/stdc++.h>
using namespace std;

bool is_valid_paranthesis_checker(string str)
{
  stack<char>st;
  for(char c: str)
  {
    if(c == '(' || c== '{' || c=='[')
    {
      st.push(c);
    }
    else if(c == ')' || c== '}' || c==']')
    {
      if(st.empty())    //nothing matches exit with false,since we are removing it will become empty.
      {
        return false;
      }
      
      char top = st.top();
      if(c == ')' && top!= '(' || c=='}' && top!='{' || c==']' && top!='[')
      {
        return false;
      }
      st.pop(); //After Checking removing the char
      return true;
      
    }
  }
}

int main()
{
  string str = "{[()]}";
  
  if(is_valid_paranthesis_checker(str))
  {
    cout<<"Valid"<<endl;
  }
  else
  {
    cout<<"Not valid"<<endl;
    
  }
}