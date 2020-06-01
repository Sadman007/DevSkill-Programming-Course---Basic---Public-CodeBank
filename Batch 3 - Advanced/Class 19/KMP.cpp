#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

vector<int> gen_prefix(string &s)
{
   int n = s.size();
   vector<int>pi(n, 0);
   for(int R = 1; R < n; R++)
   {
       int L = pi[R - 1];
       while(L > 0 && s[L] != s[R])
       {
           L = pi[L - 1];
       }
       pi[R] = L + (s[L] == s[R]);
   }
   return pi;
}

int main()
{
    string str;
    cin >> str;
    vector<int>pi = gen_prefix(str);
    for(auto it : pi) cout << it << " ";
    return 0;
}

