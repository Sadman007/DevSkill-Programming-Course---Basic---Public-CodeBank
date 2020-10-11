#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

/// nCr(n,r) = nCr(n - 1, r) + nCr(n - 1, r - 1)
/// Time Complexity: O(n * r)

int dp[2][1001]; /// O(r) --> Memory Complexity

int main()
{
    memset(dp, 0, sizeof(dp));
    int n, r;
    cin >> n >> r;
    dp[0][0] = dp[1][0] = dp[1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= r; j++)
        {
            dp[i & 1][j] = dp[(i - 1) & 1][j] + dp[(i - 1) & 1][j - 1]; /// dp[i] --> dp[i - 1]
        }
    }
    cout << dp[n & 1][r] << "\n";
    return 0;
}

