#include <bits/stdc++.h>
using namespace std;

int n, col[30][5];
int dp[30][5];

int f(int pos, int prv_clr) // as initially, prv_clr is undefined, we will be using 0.
{
    if (pos == n) return 0;
    if (dp[pos][prv_clr] != -1)
        return dp[pos][prv_clr];
    int best = INT_MAX / 2;
    for (int i = 1; i <= 3; i++)
    {
        if (prv_clr == 0 || prv_clr != i)
            best = min(best, col[pos][i] + f(pos + 1, i));
    }
    return dp[pos][prv_clr] = best;
}

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &col[i][1], &col[i][2], &col[i][3]);
        }
        printf("Case %d: %d\n", cs++, f(0, 0));
    }
    return 0;
}
