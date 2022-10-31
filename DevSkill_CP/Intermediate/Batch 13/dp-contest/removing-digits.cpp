#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

int f(int n)
{
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    string str = to_string(n);
    int min_step = INT_MAX / 2;
    for (auto c : str)
    {
        int d = c - '0';
        if (n - d >= 0 && d > 0)
        {
            min_step = min(min_step, 1 + f(n - d));
        }
    }
    return dp[n] = min_step;
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i = i + 2) f(i);
    cout << f(n) << "\n";
    return 0;
}
