#include<bits/stdc++.h>
using namespace std;


//Approach: 
bool isomorphic_string(string s, string t)
{
  if (s.empty() || t.empty()) return false;
  
  int m1[256] = {0};
  int m2[256] = {0};
  for(int i=0; i<s.length(); i++)
  {
    if(m1[s[i]] != m2[t[i]])    //to check previous postion
    {
      return false;
    }
    m1[s[i]] = i+1;
    m2[t[i]] = i+1;
  }
  return true;      //If no mismatch found.
  
}

int main()
{
  string s  = "paper";
  string t  = "title";
  if(isomorphic_string(s,t))
  {
    cout<<"Yes it is isomorphic"<<endl;
  }
  else
  {
    cout<<"Not isomorphic"<<endl;
  }
}


// s = paper   t=title

// i=0   m1[p]=1  m2[t]=1   //initially zero due to m1[256] = m2[256]={0} so we will update
// i=1   m1[a]=2  m2[i]=2   //initially zero due to m1[256] = m2[256]={0} so we will update
// i=2   m1[p]=1  m2[t]=1   //we will now update to new position m1[p] = 3 and m2[t] = 3
// i=3   m1[e]=4  m2[l]=4   //Initilaly zero as it is not seen before so no problem