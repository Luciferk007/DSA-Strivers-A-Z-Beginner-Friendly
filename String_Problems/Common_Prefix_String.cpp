#include<bits/stdc++.h>
using namespace std;


//Approach: The common prefix across all strings must exist between the smallest and largest 
//string when sorted lexicographically. So we dont have to check for middle strings.
string common_prefix(vector<string>&str)
{
  if (str.empty()) return "";
  
  int n = str.size();
  sort(str.begin(),str.end());
  string first = str[0];
  string last = str[n-1];
  int min_length = min(first.size(),last.size());
  string ans = "";
  for(int i=0; i<min_length; i++)
  {
    //Stop the loop immediately if the characters differ
    if(first[i] != last[i])
    {
      break;
    }
    else
    {
      ans += first[i];
    }
  }
  return ans;
}

int main()
{
  vector<string>str = {"flower", "flow", "flight"};
  
  cout<<common_prefix(str);
}