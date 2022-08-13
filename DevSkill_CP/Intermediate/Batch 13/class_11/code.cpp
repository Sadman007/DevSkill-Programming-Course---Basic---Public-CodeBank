#include <bits/stdc++.h>
using namespace std;

int get_gcd(int a, int b) /// get_gcd(0, b) = b
{
    if (a == 0) return b;
    return get_gcd(b % a, a);
}

int get_div_count(long long n)
{
    int c = 0;
    for (long long d = 1; d * d <= n; d++) // i <= sqrt(N) => i * i <= N
    {
        if (n % d == 0)
        {
            c++;
            if (d * d != n) c++;
        }
    }
    return c;
}

int main()
{
    cout << sum(5, 2) << " x\n";
    // freopen("out.txt", "w", stdout);
    long long n = 1000000000000007;
    cout << get_div_count(n);
    return 0;
}
