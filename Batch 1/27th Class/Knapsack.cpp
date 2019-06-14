#include <bits/stdc++.h>
using namespace std;

int W[1000];
int val[1000];
int totW,N;
int dp[1000][1000];

int knapsack(int pos,int w)
{
    if(pos<0 || w<=0) return 0;
    if(dp[pos][w]!=-1) return dp[pos][w];
    if(W[pos-1]>w) return dp[pos][w] = knapsack(pos-1,w);
    else return dp[pos][w] = max(val[pos]+knapsack(pos-1,w-W[pos]),knapsack(pos-1,w));

}

int main()
{
    cin >> N >> totW;  ///3 50
    for(int i=0;i<N;i++) cin >> val[i]; /// 100 150 90
    for(int i=0;i<N;i++) cin >> W[i];   /// 10 20 30
    memset(dp,-1,sizeof dp);
    cout << knapsack(N-1,totW);
    return 0;
}
