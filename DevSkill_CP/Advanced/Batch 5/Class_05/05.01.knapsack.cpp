#include <bits/stdc++.h>
#define LIM 20

using namespace std;

int N, K, W[1003], V[1003];
int dp[1003][1003];

///f(6,0)
int f(int in, int rem) {
    if(in == N) return 0;

    if(dp[in][rem] != -1) return dp[in][rem];
    int ans = 0;
    if(W[in] <= rem) ans = V[in]+f(in+1, rem-W[in]);
    ans = max(ans, f(in+1, rem));
    return dp[in][rem] = ans;
}

int g(int N, int K) {
    memset(dp, 0, sizeof dp);

    for(int rem=0; rem<=K; rem++) dp[N][rem] = 0;
    for(int in=N-1; in>=0; in--) {
        for(int rem=0; rem<=K; rem++) {
            int ans = 0;
            if(W[in] <= rem) ans = V[in]+dp[in+1][rem-W[in]];
            ans = max(ans, dp[in+1][rem]);
            dp[in][rem] = ans;
        }
    }
    return dp[0][K];
}

int main() {

    scanf("%d %d", &N, &K);

    for(int i=0; i<N; i++) W[i] = rand() % LIM + 1;
    for(int i=0; i<N; i++) V[i] = rand() % LIM + 1;

    cout << "DATA (w, v):";
    for(int i=0; i<N; i++) cout << " (" << W[i] << "," << V[i] << ")";
    cout << endl;

    memset(dp, -1, sizeof dp);
    cout << f(0, K) << endl;
    cout << g(N, K) << endl;

}

/**
15 40
DATA (w, v): (2,12) (8,16) (15,3) (1,8) (10,17) (5,12) (19,5) (19,3) (3,14) (5,1
3) (6,3) (6,2) (2,17) (8,19) (2,16)
128
*/
