#include <bits/stdc++.h>
using namespace std;

int W[1020];
int val[1020];
int totW,N;
int dp[1020][1020];

int f(int pos,int w)
{
    if(pos<0)
    {
        if(w>=0)
            return 0;
        return -1000000;
    }
    if(w<0)
        return -1000000;
    if(dp[pos][w]!=-1)
        return dp[pos][w];
    int r1 = val[pos]+f(pos-1,w-W[pos]);
    int r2 = f(pos-1,w);
    return dp[pos][w] = max(r1,r2);
}

void printSol(int pos,int w,int res)
{
    if(pos<0 || res<0 || w<0) return;
    if(res == dp[pos-1][w]) printSol(pos-1,w,res);
    else
    {
        printf("%d ",W[pos]);
        printSol(pos-1,w-W[pos],res-val[pos]);
    }
}


int main()
{
    scanf("%d%d",&N,&totW);  ///3 50
    for(int i=0; i<N; i++)
        scanf("%d",&val[i]); /// 100 150 90
    for(int i=0; i<N; i++)
        scanf("%d",&W[i]);  /// 10 20 30

    memset(dp,-1,sizeof dp);
    int res = f(N,totW);
    printf("RES %d\n",res);
    printSol(N,totW,res);

    return 0;
}

/**
3 50
100 150 90
10 20 30
**/
