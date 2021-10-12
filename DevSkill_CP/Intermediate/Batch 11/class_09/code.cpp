#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define MOD 1000000007

ll mod_expo(ll a, ll b) /// calculates a^b % MOD
{
    if (b == 0) return 1LL;
    if (b % 2 == 0)
    {
        ll expo_half = mod_expo(a, b / 2) % MOD;
        return (expo_half * expo_half) % MOD;
    }
    return (a * mod_expo(a, b - 1)) % MOD; /// a^b = a * a^(b-1)
}

ll big_mod(string &s, int m) /// s = 5123, m = 9
{
    ll res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res = (res * 10LL + (s[i] - '0')) % m;
    }
    return res;
}

int main()
{
    int t, cs = 1;
    cin >> t;
    while(t--)
    {
        string n;
        cin >> n;
        ll mod_res = big_mod(n, MOD - 1);
        ll res = mod_expo(3, mod_res) + 1;
        res = (res * 500000004) % MOD;
        cout << "Case " << cs++ << ": " << res << "\n";
    }
    return 0;
}
