#include <bits/stdc++.h>
using namespace std;

int w[1010],p[1010];
int n,dp[35][30003];

/**
    f(pos,rem) = 'pos' theke 'rem' capacity niye maximum profit er poriman
    f(pos,rem) = max(f(pos+1,rem), p[pos] + f(pos+1,rem-w[pos]))
**/

/**
    f(pos,rem) = 'pos' theke 'rem' capacity niye maximum item er count
    f(pos,rem) = max(f(pos+1,rem), 1 + f(pos+1,rem-w[pos]))
**/

int f(int pos,int rem) ///
{
    if(rem<0) return -100000000;
    if(pos>=n)
    {
        if(rem>=0) return 0;
        return -100000000;
    }
    if(dp[pos][rem]!=-1) return dp[pos][rem];
    int r1 , r2;
    r1 = f(pos+1,rem);
    r2 = 1 + f(pos+1,rem-w[pos]);
    return dp[pos][rem] = max(r1,r2);
}

int main()
{
    int cap;
    cin >> n >> cap;
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>p[i];
    memset(dp,-1,sizeof dp);
    cout << f(0,cap) << endl;
    return 0;
}
