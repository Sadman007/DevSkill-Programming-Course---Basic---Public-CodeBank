#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define MOD 1000000007

int dp[MAX + 5][9];
string s, t;

/// Longest Common Subsequence. s = c[hchokudai] t = c[hokudai]
int f(int is, int it) /// f(5, 2) s[0....end] & t[0...end]
{
    if (it == t.size()) return 1;
    if (is == s.size()) return 0;
    int &ret = dp[is][it];
    if (ret != -1) return ret;
    ret = f(is + 1, it) % MOD;
    if (s[is] == t[it]) ret += f(is + 1, it + 1), ret %= MOD;
    return ret;
}

int main()
{
    t = "chokudai";
    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << "\n";
    return 0;
}
