#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long x)
{
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    // freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long x;
        scanf("%lld", &x);
        long long sqx = sqrtl(x);
        if (sqx * sqx == x && is_prime(sqx))
            puts("YES");
        else puts("NO");
    }
    return 0;
}
