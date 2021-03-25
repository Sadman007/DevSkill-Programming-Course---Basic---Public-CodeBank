#include <bits/stdc++.h>

using namespace std;

/**
    10^7 * 4 => 40

    10^7

    O(NSK)
    10^3 * 10^3 * 10^4
    10^10
*/
int n, k, s;
int dp[nMax][sMax];
int dr[nMax][sMax];

int f(int in, int rem) {
    if(in == n) return rem == 0;
    if(!rem) return 0;

    if(dp[in][rem] != -1) return dp[in][rem];

    int ans = 0;
    for(int t=1; t<=k && t<=rem; t++) {
        ans += f(in+1, rem-t);
    }

    return dp[in][rem] = ans;
}

int g(int n, int k, int s) {
    memset(dp, 0, sizeof dp);
    dp[n][0] = 1;
    for(int j=0; j<=s; j++) dr[n][j] = 1;

    for(int in=n-1; in>=0; in--) {
        for(int rem=1; rem<=s; rem++) {
            dp[in][rem] = dr[in+1][rem-1];
            if(rem-k-1 >= 0) dp[in][rem] -= dr[in+1][rem-k-1];
//            for(int t=1; t<=k && t<=rem; t++) {
//                dp[in][rem] += dp[in+1][rem-t];
//            }
        }
        dr[in][0] = dp[in][0];
        for(int j=1; j<=s; j++)
            dr[in][j] = dr[in][j-1]+dp[in][j];

    }

    return dp[0][s];
}
