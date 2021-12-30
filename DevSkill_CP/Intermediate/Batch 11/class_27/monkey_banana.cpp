#include <bits/stdc++.h>
using namespace std;
int grid[205][205];
int row, n, dp[205][205];
const int dx[] = {+1, +1, +1};
const int dy[] = {-1, +0, +1};

bool is_valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < row && y < n;
}

int get_max_score(int x, int y) /// get_max_score(x, y) = starting from cell (x, y), the maximum score you can get to reach destination.
{
    if (!is_valid(x, y)) return 0;
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    int curr_max = 0;
    for (int i = 0; i < 3; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X < n && i == 0) continue;
        if (X >= n && i == 2) continue;
        curr_max = max(curr_max, grid[x][y] + get_max_score(X, Y));
    }
    return ret = curr_max;
}

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        row = n + n - 1;
        memset(dp, -1, sizeof dp);
        memset(grid, 0, sizeof grid);
        for (int i = 0; i < row; i++)
        {
            if (i < n) /// increasing row
            {
                for (int j = 0; j <= i; j++)
                {
                    scanf("%d", &grid[i][j]);
                }
            }
            else
            {
                /// i + x = row --> x = row - i
                for (int j = 0; j < row - i; j++)
                {
                    scanf("%d", &grid[i][j]);
                }
            }
        }
        printf("Case %d: %d\n", cs++, get_max_score(0, 0));
    }
    return 0;
}
