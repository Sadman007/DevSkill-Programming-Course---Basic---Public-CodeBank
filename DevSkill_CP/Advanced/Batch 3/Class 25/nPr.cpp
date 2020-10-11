#include <bits/stdc++.h>
using namespace std;

/**
    1) DP optimization --> i) D&C ii) Knuth iii) Alien Trick iv) CHT (Convex Hull Trick)
    2) Sibling DP
    3) Interval DP
    4) Tree DP
    5) Graph DP
**/

bool checkBit(int n, int pos)
{
    int val = n & (1 << pos);
    return val > 0;
}
int setBit(int n, int pos)
{
    return n | (1 << pos);
}
int bcnt(int mask)
{
    return __builtin_popcount(mask);
}

int n, r; /// 101011
int dp[12][(1 << 12) + 1];

int f(int pos, int mask)
{
    if(pos >= n) return bcnt(mask) == r;
    int &ret = dp[pos][mask];
    if(ret != -1) return ret;
    ret = 0;

    ret += f(pos + 1, mask); /// skip
    if(checkBit(mask, pos) == 0) ret += (r - bcnt(mask)) * f(pos + 1, setBit(mask, pos));

    return ret;
}

int main()
{
    cin >> n >> r;
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0) << "\n";
    return 0;
}

