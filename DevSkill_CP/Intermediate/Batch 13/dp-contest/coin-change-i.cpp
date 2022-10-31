// Add some code

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
const int MOD = 100000007;

int coin[MAX + 5];
int freq[MAX + 5];
int n, k;
int dp[52][1020];

int f(int pos, int rem)
{
    if (pos == n) return (rem == 0);
    if (rem < 0) return 0;
    int &ret = dp[pos][rem];
    if (ret != -1) return ret;
    int total = 0;
    for (int i = 0; i <= freq[pos]; i++)
    {
        total = total + f(pos + 1, rem - (i * coin[pos]));
        if (total >= MOD) total %= MOD;
    }
    return ret = total;
}

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &k);
        
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = -1;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &coin[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &freq[i]);
        }
        printf("Case %d: %d\n", cs++, f(0, k));
    }
    return 0;
}
