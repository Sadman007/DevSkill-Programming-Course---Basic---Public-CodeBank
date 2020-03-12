#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
ll g(ll M) /// O(N)
{
    ll cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cnt += min(M / i, m);
    }
    return cnt;
}
int main()
{
    cin >> n >> m >> k;
    ll L = 1;
    ll R = (n * m) + 1;
    ll M;
    int cnt = 70;
    while(cnt-- && L < R)
    {
        M = L + (R-L)/2;
        ll c = g(M); ///O(N * 40)
        if(c < k) L = M + 1;
        else R = M;
    }
    cout << L << "\n";
    return 0;
}