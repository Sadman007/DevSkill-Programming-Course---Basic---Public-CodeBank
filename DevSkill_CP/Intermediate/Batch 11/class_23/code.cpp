#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10000005

bool isComp[MAX + 5];
vector<int>primes;

void sieve()
{
    for (int i = 2; i * i <= MAX; i++)
    {
        if (!isComp[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isComp[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAX; i++)
    {
        if(!isComp[i]) primes.push_back(i);
    }
}

ll f(ll n, ll p)
{
    ll cnt = 0;
    ll base = p;
    while(n >= base)
    {
        cnt += n / base;
        base *= p;
    }
    return cnt;
}

ll solve(ll n, ll b)
{
    ll ans = INT_MAX;
    ll cpy_b = b;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= b; i++)
    {
        if(b % primes[i] == 0)
        {
            int cnt = 0;
            while(b % primes[i] == 0)
            {
                b /= primes[i];
                cnt++;
            }
            ans = min(ans, f(n, primes[i]) / cnt);
        }
    }
    if (b > 1)
    {
        ans = min(ans, f(n, b));
    }
    return ans;
}

int main()
{
    sieve();
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        ll n, b;
        scanf("%lld %lld", &n, &b);
        printf("Case %d: %lld\n", cs++, solve(n, b));
    }
    return 0;
}
