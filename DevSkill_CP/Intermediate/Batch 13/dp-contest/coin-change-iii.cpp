#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        int n, M;
        scanf("%d %d", &n, &M);
        vector<int>c(n, 0), freq(n, 0);
        for (int i = 0; i < n; i++)
            scanf("%d", &c[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &freq[i]);
        vector<int> dp(M + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            // c[i], freq[i]
            vector<int> howManyCoins(M + 1, 0); // c[i] coin koyta use korsi
            for (int curr = c[i]; curr <= M; curr++)
            {
                if (dp[curr] == 0 && howManyCoins[curr - c[i]] < freq[i])
                {
                    dp[curr] |= dp[curr - c[i]];
                    if (dp[curr] > 0)
                    {
                        howManyCoins[curr] = howManyCoins[curr - c[i]] + 1;
                    }
                }
            }
        }
        int tot = 0;
        for (int i = 1; i <= M; i++) tot += dp[i];
        printf("Case %d: %d\n", cs++, tot);
    }
    return 0;
}
