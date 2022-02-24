#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

int f(int n, int r)
{
    if(n < r) return 0;
    if(n == r || r == 0) return 1;
    if(dp[n][r] != -1) return dp[n][r];
    dp[n][r] = f(n - 1, r - 1) + f(n - 1, r);
    return dp[n][r];
}

int f2(int n, int r)
{
    int gap = n - r;
    int res = 1;
    int dw = 1;
    while(gap--)
    {
        res *= (n--);
        res /= (dw++);
    }
    return res;
}

int main()
{
    //memset(dp, -1, sizeof(dp));
    cout << f2(103, 101) << endl;
    return 0;
}
