#include <bits/stdc++.h>
using namespace std;
int arr[5005];
long long dp[5002][5002][2];

long long f(int L, int R, int p)
{
    if (L > R) return 0;
    auto &ret = dp[L][R][p];
    if (ret) return ret;
    if (p == 0)
        ret = max(arr[L] + f(L + 1, R, 1), arr[R] + f(L, R - 1, 1));
    else
        ret = min(f(L + 1, R, 0), f(L, R - 1, 0));
    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("%lld\n", f(0, n - 1, 0));
    return 0;
}
