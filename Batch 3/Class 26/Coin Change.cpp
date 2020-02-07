#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007

int n,bill,coins[105];

int dp[10005][105];

int f(int rem,int pos) /// O(rem * pos)
{
    if(pos >= n) return 0;
    if(rem < 0) return 0;
    if(rem == 0) return 1;
    if(dp[rem][pos] != -1) return dp[rem][pos];
    return dp[rem][pos] = (f(rem - coins[pos],pos) % MOD + f(rem, pos + 1) % MOD) % MOD;
}

int main()
{
    int t, cs = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &bill);
        for(int i = 0; i < n ; i++) scanf("%d", &coins[i]);

        for(int i = 0; i <= bill; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                dp[i][j] = -1;
            }
        }

        printf("Case %d: %d\n",cs++,f(bill,0));
    }
    return 0;
}
