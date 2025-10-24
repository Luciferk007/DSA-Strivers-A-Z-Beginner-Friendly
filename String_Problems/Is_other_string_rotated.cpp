#include<bits/stdc++.h>
using namespace std;


//Approach: 

bool isrotation(string s, string t)
{
  if(s.size() != t.size() || s.empty() || t.empty()) return false;
  
  for(int i=0; i<s.size(); i++)
  {
    if(s[i] == t[i])
    {
      return true;
    }
    else
    {
      s.push_back(s[i]);
      s.erase(i,1);
    }
  }
}

int main()
{
  string s  = "rotation";
  string t  = "tionrota";
  if(isrotation(s,t))
  {
    cout<<"Yes it is rotated"<<endl;
  }
  else
  {
    cout<<"Not rotated"<<endl;
  }
}