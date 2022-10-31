#include <bits/stdc++.h>
using namespace std;
string grid[1010];
int n;
long long dp[1010][1010];

const int MOD = 1000000007;

long long findWays(int r, int c)
{
    if (r == n - 1 && c == n - 1) return grid[r][c] == '.';
    if (r >= n || c >= n || grid[r][c] == '*') return 0;
    if (dp[r][c] != -1) return dp[r][c];
    auto res = findWays(r + 1, c) + findWays(r, c + 1);
    if (res >= MOD) res %= MOD;
    return dp[r][c] = res;
}

int main()
{
    int T = 1, cs = 1;
    while(T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> grid[i];
        memset(dp, -1, sizeof dp);
        cout << findWays(0, 0) << "\n";
    }
    return 0;
}

