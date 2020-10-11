#include <bits/stdc++.h>
using namespace std;

int n, dp[25][3], r[25], b[25], g[25];

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &r[i], &g[i], &b[i]);
        }
        dp[0][0] = r[0];
        dp[0][1] = g[0];
        dp[0][2] = b[0];
        for(int i = 1; i < n; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g[i];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
        }
        printf("Case %d: %d\n", cs++, min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}));
    }
    return 0;
}
