#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

int n, arr[100], st[100][7], log[100];

int f(int a, int b)
{
    ///return min(a, b);
    ///return max(a, b);
    return __gcd(a, b);
}

void pre()
{
    for(int i = 1; i <= n; i++) log[i] = log2(i);

    for(int i = 0; i < n; i++) st[i][0] = arr[i];
    int K = log2(n);
    for(int j = 1; j <= K; j++)
    {
        for(int i = 0; i + (1 << j) - 1 < n; i++)
        {
            ///int L = i;
            ///int R = i + (1 << j) - 1;
            ///if(R >= n) break;
            st[i][j] = f(st[i][j - 1] , st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int getMin(int L, int R) /// O(1)
{
    int K = log[R - L + 1];
    return f(st[L][K] , st[R - (1 << K) + 1][K]);
}

int getRangeSum(int L, int R)
{
    int len = R - L + 1;
    /// code here
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    pre();
    return 0;
}
