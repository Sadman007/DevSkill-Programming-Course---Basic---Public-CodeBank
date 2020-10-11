#include <bits/stdc++.h>
using namespace std;
int n, a[17], b[17], cost[17][17], dp[16][(1 << 16) + 1];
bool checkBit(int n, int pos)
{
    int val = n & (1 << pos);
    return val > 0;
}
int setBit(int n, int pos)
{
    return n | (1 << pos);
}

int f(int x_v, int mask)
{
    if(x_v >= n) return 0;
    int &ret = dp[x_v][mask];
    if(ret != -1) return ret;
    ret = INT_MAX / 2;
    for(int x_b = 0; x_b < n; x_b++)
    {
        if(checkBit(mask, x_b) == 0)
        {
            ret = min(ret, cost[x_b][x_v] + f(x_v + 1, setBit(mask, x_b)));
        }
    }
    return ret;
}

int main()
{
    while(cin >> n)
    {
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cost[i][j] = abs(i - j) + abs(a[i] - b[j]);
            }
        }

        memset(dp, -1, sizeof(dp));
        cout << f(0, 0) << "\n";
    }
    return 0;
}
