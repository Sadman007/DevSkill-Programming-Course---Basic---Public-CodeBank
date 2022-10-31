#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        int n, K;
        scanf("%d %d", &n, &K);
        vector<int>c(n, 0);
        for (int i = 0; i < n; i++)
            scanf("%d", &c[i]);
        vector<int> dp(K + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int curr = c[i]; curr <= K; curr++)
            {
                dp[curr] += dp[curr - c[i]];
                if (dp[curr] >= 100000007)
                    dp[curr] %= 100000007;
            }
        }
        printf("Case %d: %d\n", cs++, dp[K]);
    }
    return 0;
}
