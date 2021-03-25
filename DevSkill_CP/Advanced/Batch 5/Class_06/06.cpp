#include <bits/stdc++.h>
#define MAX 100000008

using namespace std;

int f(int in, int last) {
    if(in == n) return 0;
    if(dp[in][last] != -1) return dp[in][last];

    int ans = MAX;
    if(last != 1) ans = min(ans, R[in]+f(in+1, 1));
    if(last != 2) ans = min(ans, G[in]+f(in+1, 2));
    if(last != 3) ans = min(ans, B[in]+f(in+1, 3));

    return dp[in][last] = ans;
}

int g(int n) {
    memset(dp, 0, sizeof dp);
    for(int in=n-1; in>=0; in--) {
        for(int last=0; last<4; last++) {
            int ans = MAX;
            if(last != 1) ans = min(ans, R[in]+dp[in+1][1]);
            if(last != 2) ans = min(ans, G[in]+dp[in+1][2]);
            if(last != 3) ans = min(ans, B[in]+dp[in+1][3]);
            dp[in][last] = ans;
        }
    }
    return dp[0][0];
}
