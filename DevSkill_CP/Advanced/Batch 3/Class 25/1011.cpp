#include <bits/stdc++.h>
using namespace std;
int n, grid[16][16];
int dp[16][(1 << 16) + 1];
bool checkBit(int n, int pos)
{
    int val = n & (1 << pos);
    return val > 0;
}
int setBit(int n, int pos)
{
    return n | (1 << pos);
}

/// TC: O(N * 2^N * N) = O(2^N * N^2)
int f(int col, int mask) /// mask represent korbe kon kon row available, 0 = available, 1 = not available
{
    if(col >= n) return 0;
    int &ret = dp[col][mask];
    if(ret != -1) return ret;
    ret = 0;
    int max_sum = 0;

    for(int row = 0; row < n; row++)
    {
        if(checkBit(mask, row) == 0)
        {
            max_sum = max(max_sum, grid[row][col] + f(col + 1, setBit(mask, row)));
        }
    }
    return ret = max_sum;
}

int main()
{
    int t, cs = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d", &grid[i][j]);
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << "Case " << cs++ << ": " << f(0, 0) << "\n";
    }
    return 0;
}
