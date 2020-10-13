#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, q, arr[300005], dp[300005][2];

ll f(int pos, int parity)
{
    if(pos >= n) return 0;
    if(dp[pos][parity] != -1) return dp[pos][parity];

    /// pos-tomo element ke skip korlam
    ll res = f(pos + 1, parity);

    /// pos-tomo element ke ami niboi nibo
    if(parity == 0) /// even shongkhok element nisi
    {
        res = max(res, arr[pos] + f(pos + 1, parity ^ 1));
    }
    else /// odd shongkhok element nisi
    {
        res = max(res, -arr[pos] + f(pos + 1, parity ^ 1));
    }
    return dp[pos][parity] = res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld %lld", &n, &q);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = dp[i][1] = -1;
        }
        printf("%lld\n", f(0, 0));
    }
    return 0;
}
