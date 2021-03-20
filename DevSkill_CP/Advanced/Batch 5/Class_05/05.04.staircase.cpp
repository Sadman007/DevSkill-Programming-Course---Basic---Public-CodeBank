#include <bits/stdc++.h>

using namespace std;

int n, dp[102][102];

int f(int n, int last) {
    if(!n) return 1;

    if(dp[n][last] != -1) return dp[n][last];
    int ans = 0;
    for(int t=last+1; t<=n; t++) {
        ans += f(n-t, t);
    }
    return dp[n][last] = ans;
}

int g(int N) {
    memset(dp, 0, sizeof dp);
    for(int last=0; last<=N; last++) dp[0][last] = 1;

    for(int n=1; n<=N; n++) {
        for(int last=0; last<=N; last++) {
            int ans = 0;
            for(int t=last+1; t<=n; t++) {
                ans += dp[n-t][t];
            }
            dp[n][last] = ans;
        }
    }
    return dp[N][0];
}

int main() {
    scanf("%d", &n);
    memset(dp, -1, sizeof dp);
    cout << f(n, 0) << endl;
    cout << g(n) << endl;90


}
