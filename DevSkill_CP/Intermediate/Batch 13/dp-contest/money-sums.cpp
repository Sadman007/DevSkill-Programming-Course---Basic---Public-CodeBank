#include <bits/stdc++.h>
using namespace std;

const int M = 100005;
const int NMAX = 100;
int c[NMAX + 5], freq[NMAX + 5], mp[1010], dp[M + 5];

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int item;
        scanf("%d", &item);
        mp[item]++;
    }
    n = 0;

    for (int i = 1; i <= 1000; i++)
    {
        if (mp[i] > 0)
        {
            c[n] = i;
            freq[n] = mp[i];
            ++n;
        }
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        // c[i], freq[i]
        vector<int> howManyCoins(M + 1, 0); // c[i] coin koyta use korsi
        for (int curr = c[i]; curr <= M; curr++)
        {
            if (dp[curr] == 0 && howManyCoins[curr - c[i]] < freq[i])
            {
                dp[curr] += dp[curr - c[i]];
                if (dp[curr] > 0)
                {
                    ++cnt;
                    howManyCoins[curr] = howManyCoins[curr - c[i]] + 1;
                }
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= M; i++)
    {
        if (dp[i] > 0) printf("%d ", i);
    }
    return 0;
}
