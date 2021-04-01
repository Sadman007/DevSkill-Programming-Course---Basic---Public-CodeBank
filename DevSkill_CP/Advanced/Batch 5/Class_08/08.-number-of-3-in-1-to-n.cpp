#include <bits/stdc++.h>

using namespace std;

/**
2...
3542

num[3] = 2
num[2] = 42
num[1] = 542
num[0] = 3542

*/

int N, pow10[12], num[12];
vector<int> d;
int dp[12][2]; /// 0 -> soman, 1 -> choto

int f(int in, int last) {
    if(in == d.size()) return 0;
    if(dp[in][last] != -1) return dp[in][last];
    int ans = 0;

    if(!last) {
        for(int v=0; v<=d[in]; v++) {
            ans += f(in+1, (v < d[in]));
        }
        if(3 < d[in]) ans += pow10[d.size()-in-1];
        else if(3 == d[in]) ans += num[in+1];
    }

    else {
        for(int v=0; v<10; v++) {
            ans += f(in+1, 1);
        }
        ans += pow10[d.size()-in-1];
    }

    return dp[in][last] = ans;
}


int main() {
    scanf("%d", &N);
    int n = N;
    pow10[0] = 1;
    for(int i=1; i<10; i++) pow10[i] = pow10[i-1]*10;
    while(N) {
        d.push_back(N%10);
        N /= 10;
    }
    reverse(d.begin(), d.end());

    for(int i=0; i<d.size(); i++) {
        num[i] = n%pow10[d.size()-i];
    }
    num[d.size()] = 1;



    memset(dp, -1, sizeof dp);
    printf("%d\n", f(0, 0));


}
