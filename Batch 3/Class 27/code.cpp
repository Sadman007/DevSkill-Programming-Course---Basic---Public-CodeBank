#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

int n,W;
int v[100], w[100];
int dp[100][100];

int f(int pos,int rem) /// O(n * W)
{
    if(rem < 0) return INT_MIN / 2;
    if(rem == 0 || pos >= n) return 0;

    if(dp[pos][rem] != -1) return dp[pos][rem];

    int leftTree = f(pos + 1,rem - w[pos]) + v[pos];
    int rightTree = f(pos + 1,rem);
    return dp[pos][rem] = max(leftTree,rightTree);
}


int main()
{
    cin >> n >> W;
    for(int i = 0; i < n;i++) cin >> v[i];
    for(int i = 0; i < n;i++) cin >> w[i];
    memset(dp,-1,sizeof dp);
    cout << f(0,W) << "\n";
    return 0;
}
