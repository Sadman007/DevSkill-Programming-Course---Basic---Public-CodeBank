#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
int dp[10101];
int coin[110];
int n;

int solve(int k)
{
    dp[0]=1;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(j>=coin[i])
            {
                dp[j]+=dp[j-coin[i]];
            }
            dp[j]%=MOD;
        }
    }
    return dp[k];
}

int main()
{

    int siz,t,k;
    scanf("%d",&t);
    for(int x=1; x<=t; x++)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++) scanf("%d",&coin[i]);
        printf("Case %d: %d\n",x,solve(k)%MOD);
    }
    return 0;
}
