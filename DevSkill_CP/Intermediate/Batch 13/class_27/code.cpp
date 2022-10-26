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
    if (dp[pos][rem] != -1) return dp[pos][rem];
    int total = 0;
    for (int i = 0; i <= freq[pos]; i++)
    {
        total = (total + f(pos + 1, rem - (i * coin[pos]))) % MOD;
    }
    dp[pos][rem] = total;
    return total;
}

int main()
{
    int T, cs = 1;
    cin >> T;
    while(T--)
    {
        memset(dp, -1, sizeof dp);
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> coin[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> freq[i];
        }
        cout << "Case " << cs++ << ": " << f(0, k) << "\n";
    }
    return 0;
}
