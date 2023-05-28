#include <bits/stdc++.h>
using namespace std;

// returns the number of trailing zeroes in n!
long long get_trailing_zeroes_count(long long n)
{
    long long fcnt = 0, base = 5;
    while(n >= base)
    {
        fcnt += n / base;
        base *= 5;
    }
    return fcnt;
}

long long find_N(long long Q)
{
    long long L = 1, R = 1000000000LL;
    while(L < R)
    {
        long long M = L + (R - L) / 2;
        auto tzcnt = get_trailing_zeroes_count(M);
        if (tzcnt < Q) L = M + 1;
        else R = M;
    }
    return L;
}

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        long long Q;
        scanf("%lld", &Q);
        auto N = find_N(Q);
        printf("Case %d: ", cs++);
        if (Q != get_trailing_zeroes_count(N))
            puts("impossible");
        else
            printf("%lld\n", N);
    }
    return 0;
}
