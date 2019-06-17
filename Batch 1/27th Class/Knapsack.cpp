#include <bits/stdc++.h>
using namespace std;

int W[1020];
int val[1020];
int totW,N;
int dp[1020][1020];

int f(int pos,int w)
{
    if(pos>=N)
    {
        if(w>=0)
            return 0;
        return -1000000;
    }
    if(w<0)
        return -1000000;
    if(dp[pos][w]!=-1)
        return dp[pos][w];
    return dp[pos][w] = max(val[pos]+f(pos+1,w-W[pos]),f(pos+1,w));
}

int main()
{
    scanf("%d%d",&N,&totW);  ///3 50
    for(int i=0; i<N; i++)
        scanf("%d",&val[i]); /// 100 150 90
    for(int i=0; i<N; i++)
        scanf("%d",&W[i]);  /// 10 20 30

    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<=N; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << f(0,totW) << "\n";
    return 0;
}
