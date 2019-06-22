#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
#define ll long long
ll dp[101][1010];
int n,c[101],f[101];

ll slv(int pos,int rem)
{
    if(pos>=n) return (rem==0);

    if(dp[pos][rem]!=-1) return dp[pos][rem]%MOD;

    ll res = 0;
    for(int i=0; i<=f[pos]; i++)
    {
        if(c[pos]*i <= rem)
        {
            res+=slv(pos+1,rem-(c[pos]*i));
            while(res<0) res+=MOD;
            if(res>MOD) res%=MOD;
        }
        else break;
    }
    return dp[pos][rem]=res;
}


int main()
{
    int t,K,cs=1;
    scanf("%d",&t); /// test case
    while(t--)
    {
        scanf("%d%d",&n,&K); /// n = koy dhoroner coin ase , K = target value
        for(int i=0; i<n; i++) scanf("%d",&c[i]); /// kon kon coin
        for(int i=0; i<n; i++) scanf("%d",&f[i]); /// kon coin koyta ase

        /// memset
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=K;j++) dp[i][j] = -1;
        }

        printf("Case %d: %lld\n",cs++,slv(0,K));
    }
    return 0;
}
