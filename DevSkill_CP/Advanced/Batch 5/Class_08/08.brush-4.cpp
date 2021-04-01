#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int setbit(int mask, int p) { return mask | (1<<p); }
int chkbit(int mask, int p) { return mask & (1<<p); }

int n, x[17], y[17];
int mask[17][17], dp[(1<<16)];

pii dhal(int i, int j) {
    int dx = x[i]-x[j];
    int dy = y[i]-y[j];
    if(dx < 0) {
        dx = -dx;
        dy = -dy;
    }
    int g = __gcd(dx,dy);
    dx /= g;
    dy /= g;
    return {dy, dx};
}

int f(int curmask) {
    if(curmask+1 == (1<<n)) return 0;
    if(dp[curmask] != -1) return dp[curmask];

    int u, ans = 100000008;
    for(u=0; u<n && chkbit(curmask, u); u++);
    for(int v=u; v<n; v++) {
        ans = min(ans, 1+f(curmask|mask[u][v]));
    }
    return dp[curmask] = ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        memset(mask, 0, sizeof mask);
        memset(dp, -1, sizeof dp);
        for(int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);

        for(int u=0; u<n; u++) {
            for(int v=0; v<n; v++) {
                /// u->v
                if(u == v) {
                    mask[u][v] = setbit(0, u);
                    continue;
                }
                mask[u][v] = setbit(setbit(0, u), v);
                for(int w=0; w<n; w++) if(w != u && w != v) {
                    if(dhal(u,v) == dhal(u,w)) mask[u][v] = setbit(mask[u][v], w);
                }
            }
        }

        printf("Case %d: %d\n", t, f(0));
    }
}
