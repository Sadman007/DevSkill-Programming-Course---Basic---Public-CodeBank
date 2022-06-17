#include <bits/stdc++.h>
using namespace std;
#define MAX 100000000

bool composite[MAX + 5];

/// sieve of eratosthenes
void sieve(int n) /// O(N * log2(log2(N))
{
    composite[1] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (composite[i] == false) /// if `i` is a prime number
        {
            for (int j = i * i; j <= n; j += i)
            {
                composite[j] = true;
            }
        }
    }
    int primeCount = 0;
    for (int i = 2; i <= n; i++)
    {
        primeCount += composite[i] == false;
    }
    printf("%d\n", primeCount);
}

int main()
{
    sieve(MAX);
    return 0;
}
