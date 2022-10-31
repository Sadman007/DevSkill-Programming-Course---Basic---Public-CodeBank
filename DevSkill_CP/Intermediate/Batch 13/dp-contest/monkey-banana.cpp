#include <bits/stdc++.h>
using namespace std;

int n, arr[205][205];
int dp[205][205];

bool is_invalid(int r, int c)
{
    if (c < 1) return true;
    if (r <= n && c > r) return true;
    if (r > n && c > (n - r%n)) return true;
    if (r > n + n - 1) return true;
    return false;
}

int f(int r, int c)
{
    if (is_invalid(r, c)) return 0;
    if (dp[r][c] != -1)
        return dp[r][c];
    int direction = r < n ? +1 : -1;
    return dp[r][c] = arr[r][c] + max(f(r + 1, c), f(r + 1, c + direction));
}

int main()
{
    // freopen("out.txt", "w", stdout);
    int cs = 1, T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int r = n + n - 1;
        for (int i = 1; i <= r; i++)
        {
            int c = i <= n ? i : n - (i % n);
            for (int j = 1; j <= c; j++)
            {
                scanf("%d", &arr[i][j]);
                dp[i][j] = -1;
            }
        }
        printf("Case %d: %d\n", cs++, f(1, 1));
    }
    return 0;
}
