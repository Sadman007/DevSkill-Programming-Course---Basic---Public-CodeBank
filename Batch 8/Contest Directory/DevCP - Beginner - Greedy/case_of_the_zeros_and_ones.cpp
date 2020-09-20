#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string str;
  cin >> n >> str;
  stack<char>stk;
  for(int i = 0; i < n; i++)
  {
    if(!stk.empty() &&
     stk.top() == '0' &&
     str[i] == '1')
     stk.pop();
     
    else if(!stk.empty() &&
     stk.top() == '1' &&
     str[i] == '0')
     stk.pop();
     
    else stk.push(str[i]);
  }
  cout << stk.size() << "\n";
  return 0;
}