#include <bits/stdc++.h>

using namespace std;

bool chkbit(int mask, int p) { return mask & (1 << p); }
int setbit(int mask, int p) { return mask | (1 << p); }
int togbit(int mask, int p) { return mask ^ (1 << p); }
/// int resetbit(int mask, int p);

int N;
vector<vector<int>> G;
int dp[(1<<16)];

int f(int u, int mask) {
//    u = __builtin_popcount(mask);
    if(mask+1 == (1<<N)) return 0;
    if(dp[mask] != -1) return dp[mask];
    int ans = 0;
    for(int v=0; v<N; v++) {
        if(!chkbit(mask, v)) {
            ans = max(ans, G[u][v]+f(u+1, setbit(mask, v)));
        }
    }
    return dp[mask] = ans;
}

int maxProfit(vector<vector<int>> &g) {
    G = g;
    N = G.size(); /// G[i][j] means edge ase naki nai
    memset(dp, -1, sizeof dp);

    return f(0, 0);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int n;
        vector<vector<int>> g;
        scanf("%d", &n);
        g.resize(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int x;
                scanf("%d", &x);
                g[i].push_back(x);
            }
        }

        printf("Case %d: %d\n", t, maxProfit(g));
    }
}
