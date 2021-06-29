#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

ll solve(ll n, ll k)
{
    ll L = 1, R = 1e18;
    while(L < R)
    {
        ll M = L + (R - L)/2;
        ll cnt_of_val_in_range = M - (M / n);
        if(cnt_of_val_in_range < k)
            L = M + 1;
        else
            R = M;
    }
    return L;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    return 0;
}
