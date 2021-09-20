#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

ll f(int n, int k)
{
    ll L = 1, R = 1000000000000LL;
    while(L < R)
    {
        ll M = (L + R) / 2;
        ll cnt = M - (M / n);
        if (cnt < k) L = M + 1;
        else R = M;
    }
    return L;
}

int main()
{
    ll t, n, k;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld%lld", &n, &k);
        printf("%lld\n", f(n, k));
    }
    return 0;
}
