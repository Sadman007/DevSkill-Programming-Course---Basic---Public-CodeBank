#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;
int dp[10005];
const int MOD = 10000007;

int fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if (n < 0) return 0;
    if (dp[n] != -1) return dp[n];
    int res = 0;
    for (int i = 1; i <= 6; i++) {
        res = (res + fn(n - i)) % MOD;
    }
    return dp[n] = res;
}
int main() {
    int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        memset(dp, -1, sizeof dp);
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", caseno, fn(n) % MOD);
    }
    return 0;
}