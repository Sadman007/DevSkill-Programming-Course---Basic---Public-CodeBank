#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007

int n;
int dp[52][1002];
int a_i[52], c_i[52];

int find_ways(int pos, int rem)
{
    if (pos >= n) return (rem == 0);
    if (rem < 0) return 0;
    int &ret = dp[pos][rem];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i <= c_i[pos]; i++)
    {
        int curr = find_ways(pos + 1, rem - (a_i[pos] * i)) % MOD;
        ret = (ret + curr) % MOD;
    }
    return ret;
}

int main()
{
    int t, k, cs = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a_i[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &c_i[i]);
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = -1;
            }
        }
        printf("Case %d: %d\n", cs++, find_ways(0, k));
    }
    return 0;
}
