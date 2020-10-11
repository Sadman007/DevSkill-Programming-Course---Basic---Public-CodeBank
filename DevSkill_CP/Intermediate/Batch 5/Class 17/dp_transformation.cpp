#include <bits/stdc++.h>
using namespace std;

int dp[100000];

int getMinMove(int u,int v)
{
    if(u == v) return 0;
    if(u > 2*v || u < 0) return INT_MAX/2;
    if(dp[u] != -1) return dp[u];
    dp[u] = INT_MAX/2;
    return dp[u] = 1 + min(getMinMove(2*u,v),getMinMove(u-1,v));
}

int main()
{
    memset(dp,-1,sizeof dp);
    int a,b;
    cin >> a >> b;
    cout << f(a,b) << endl;
    return 0;
}
