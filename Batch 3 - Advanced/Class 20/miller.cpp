#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

ll rp(ll a, ll b, ll mod)
{
    ll res = 0;
    while(b > 0)
    {
        if(b % 2 == 1) res = (res + a) % mod;

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
    ll x = binpower(a, d, n); /// i) a^d % n
    if (x == 1 || x == n - 1) return false; /// n probably prime
    for (int r = 0; r < s - 1; r++) /// O(log(n) ^ 2)
    {
        x = rp(x, x, n); /// ii) x^2 % n
        if (x == n - 1) return false; /// n probably prime
    }
    return true; /// n composite
};

bool MillerRabin(ll n)   // returns true if n is prime, else returns false.
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }

    vector<int>bases{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for (int a : bases) /// O(|base| * (logN)^2) = O(12 * 3600)
    {
        if (n == a) return true;
        if (check_composite(n, a, d, s)) return false;
    }
    return true; /// highly probable that n is a prime number
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ll n;
        scanf("%lld", &n);
        if(MillerRabin(n)) puts("YES");
        else puts("NO");
    }
    return 0;
}
