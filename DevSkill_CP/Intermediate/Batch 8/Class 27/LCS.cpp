#include <bits/stdc++.h>
using namespace std;

string A, B;
int n, m, dp[1010][1010];

int f(int pA, int pB)
{
    if(pA >= n || pB >= m) return 0;
    if(dp[pA][pB] != -1) return dp[pA][pB];
    int f1, f2;
    f1 = f2 = 0;
    if(A[pA] == B[pB])
        f1 = 1 + f(pA + 1, pB + 1);
    f2 = max(f(pA + 1, pB), f(pA, pB + 1));
    return dp[pA][pB] = max(f1, f2);
}

int main()
{
    cin >> A >> B;
    n = A.size();
    m = B.size();
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0) << "\n";
    return 0;
}

