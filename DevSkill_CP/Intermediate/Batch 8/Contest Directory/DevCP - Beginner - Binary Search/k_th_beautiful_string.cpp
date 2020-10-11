#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,n,m;
    cin >> t;
    while(t--)
    {
      cin >> n >> m;
      --m;
      ll p1 = sqrtl(1 + (8LL * m)) - 1;
      p1/=2;
      ll p2 = n - m + (p1*(p1+1))/2;
      p1 = n - 1 - p1;
      for(int i = 1; i <= n; i++)
      {
        if(i == p1 || i == p2) cout << "b";
        else cout << "a";
      }
      cout << "\n";
    }
}