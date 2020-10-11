#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rp(ll a, ll b, ll mod)
{
    ll res = 0;
    while(b)
    {
        if(b & 1) res = (res + a) % mod;

        a = (a << 1) % mod;
        b = (b >> 1);
    }
    return res;
}

ll binpower(ll base, ll e, ll mod)
{
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = rp(result, base, mod);
        base = rp(base, base, mod);
        e >>= 1;
    }
    return result;
}

bool check_composite(ll n, ll a, ll d, int s)
{
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = rp(x, x, n);
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n)   // returns true if n is prime, else returns false.
{
    if (n < 2) return false;
    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }
    for (int a : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a) return true;
        if (check_composite(n, a, d, r)) return false;
    }
    return true;
}

ll f(ll x, ll c, ll mod)
{
    return (rp(x, x, mod) + c) % mod;
}

ll rho(ll n) /// Time Complexity: O(N^(1/4) * logN)
{
    if(n % 2 == 0) return 2;
    if(MillerRabin(n) == 1) return n;

    ll x = (rng() % n) + 1;
    ll y = x;
    ll g = 1;
    ll c = (rng() % n) + 1;

    while(g == 1)
    {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = __gcd(abs(x - y), n);
    }
    return g == n ? rho(n) : g;
}

int main()
{
    ll n;
    while(scanf("%lld", &n) == 1)
    {
        if(!n) break;
        map<ll, int>facts;
        while(n > 1)
        {
            ll dv = rho(n);
            while(1)
            {
                ll tmpdv = rho(dv);
                if(dv == tmpdv) break;
                dv = tmpdv;
            }
            n /= dv;
            facts[dv]++;
        }
        int sz = facts.size();
        int idx = 0;
        for(auto it : facts)
        {
            printf("%lld^%d", it.first, it.second);
            idx++;
            if(idx < sz) printf(" ");
            else puts("");
        }
    }
    return 0;
}
