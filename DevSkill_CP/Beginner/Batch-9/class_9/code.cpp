#include <bits/stdc++.h>
using namespace std;

int find_N(int n, int k) /// O(log2N * log5N) ~ O(log2N)^2
{
    int L = 0, R = 2000000001; /// [0, 10^9]
    while(L < R)
    {
        int M = L + (R - L) / 2;
        int cnt = M - (M / n);
        if (cnt < k)
        {
            L = M + 1;
        }
        else
        {
            R = M;
        }
    }
    return L;
}

int main()
{
    int T, Q, cs = 1, n, k;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &k);
        printf("%d\n", find_N(n, k));
    }
    return 0;
}
