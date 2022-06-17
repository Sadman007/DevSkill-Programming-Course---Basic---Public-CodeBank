#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

/// O(Nlog(N))
int getPhi(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (__gcd(i, n) == 1)
            cnt++;
    }
    return cnt;
}

int phi[MAX + 5];
void sieveForPhi(int n)
{
    for (int i = 1; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i) /// i is prime.
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

bool isPrime(int n)
{
    return phi[n] == n - 1;
}

int main()
{
    sieveForPhi(MAX);
    for (int i = 1; i <= 100; i++)
    {
        if (isPrime(i)) cout << i << "\n";
    }
    return 0;
}
