#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long getExpo(long long a, long long b)
{
    /// base case
    if (b == 0) return 1;

    /// b is even
    if (b % 2 == 0)
    {
        long long value = getExpo(a, b / 2) % MOD;
        return (value * value) % MOD;
    }

    /// b is odd
    return (a * getExpo(a, b - 1) % MOD) % MOD;
}

int main()
{
    cout << getExpo(5, 245646519LL);
    return 0;
}
