#include <bits/stdc++.h>
using namespace std;

// Russian Peasant Multiplication Algorithm
const int M = 11; // M = 10^17 + 1
// t = 10^17
// t * t = 10^34
// phi(M) = 100, cycle length = d, phi(M) % d = 0
long long getExp(long long a, long long b)
{
    if (b == 0) return 1;
    if (b % 2 == 0) // b is even, ba jor
    {
        auto t = getExp(a, b / 2) % M;
        return (t * t) % M;
    }
    return (a * getExp(a, b - 1) % M) % M;
}

long long getFactorial(int n)
{
    long long res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = (res * i) % M;
    }
    return res;
}

long long f(int n)
{
    if (n == 0) return 1;
    auto res = (1LL * n * f(n - 1) % M) % M; // res = 2
    //cout << "Razu " << res << "\n"; // Razu 2
    //getchar();
    return res;
}

int main()
{
    /**
    cout << getFactorial(200000) << "\n";
    return 0;
    cout << getFactorial(212) << "\n";
    auto down = (getFactorial(73) * getFactorial(139)) % M;
    cout << (getFactorial(212) * getExp(down, M - 2)) % M << "\n";
    **/

    for (int i = 0; i < 1000; i++)
    {
        cout << i << ": " << getExp(2, i) << "\n";
    }

    return 0;
}
