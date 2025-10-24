#include<bits/stdc++.h>
using namespace std;


//Approach: 
bool anagram(string s, string t)
{
  if (s.empty() || t.empty()) return false;
  
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  
  return s==t;
  
}

//If sorting is not allowed

bool isanagram(string s, string t)
{
  map<char,int>count;
  for(char c: s)
  {
    count[c]++;
  }
  for(char c: t)
  {
    cout[t]--;
  }
  for(auto it:count)
  {
    if(it.second != 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  string s  = "CAT";
  string t  = "ACT";
  if(anagram(s,t))
  {
    cout<<"Yes it is Anagramic"<<endl;
  }
  else
  {
    cout<<"Not Anagramic"<<endl;
  }
}
