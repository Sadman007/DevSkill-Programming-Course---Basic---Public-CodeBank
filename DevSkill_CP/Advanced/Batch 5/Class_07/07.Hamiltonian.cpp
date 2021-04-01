#include <bits/stdc++.h>

using namespace std;

bool chkbit(int mask, int p) { return mask & (1 << p); }
int setbit(int mask, int p) { return mask | (1 << p); }
int togbit(int mask, int p) { return mask ^ (1 << p); }
/// int resetbit(int mask, int p);

int N;
vector<vector<int>> G;
int dp[16][(1<<16)];

int f(int u, int mask) {
    if(mask+1 == (1<<n)) return 1;
    if(dp[u][mask] != -1) return dp[u][mask];
    int ans = 0;
    for(int v=0; v<n; v++) {
        if(G[u][v] && !chkbit(mask, v)) {
            ans |= f(v, setbit(mask, v));
        }
    }
    return dp[u][mask] = ans;
}

int hamPath(vector<vector<int>> g) {
    G = g;
    N = G.size(); /// G[i][j] means edge ase naki nai
    memset(dp, -1, sizeof dp);

    int ans = 0;
    for(int u=0; u<N; u++) {
        ans |= f(u, setbit(0, u));
    }
    return ans;
}

int main() {


}
