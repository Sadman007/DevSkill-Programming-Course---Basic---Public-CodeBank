#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int nop[MAX + 5];
vector<int> primes; // primes = {2, 3, 5, 7, ... }

int find_prime_count(int n)
{
    return nop[n];
}

bool find_elem(vector<int>&v, int elem)
{
    return binary_search(v.begin(), v.end(), elem);
}

/// O(NloglogN)
void sieve()
{
    vector<bool> comp(MAX + 5, 0);
    for (int i = 2; i * i <= MAX; i++)
    {
        if (comp[i] == 0)
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                comp[j] = 1;
            }
        }
    }
    primes.clear();
    primes = {2};
    for (int i = 3; i <= MAX; i += 2)
    {
        if (!comp[i])
            primes.push_back(i);
    }
}

/// O(sqrt(N)/lnN)
int find_prime_contrib(int n) // n = 15 -> 3 * 5
{
    int cnt = 0;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            while(n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
            }
        }
    }
    if (n > 1) cnt++;
    return cnt;
}

/// nop[] array ke decorate kora
void preprocess()
{
    sieve();
    nop[2] = 1;
    for (int i = 3; i <= MAX; i++)
    {
        nop[i] = nop[i - 1] + find_prime_contrib(i);
    }
}

/// O(NloglogN + N * (sqrt(N) / lnN) + T)
int main()
{
    /// O(NloglogN + N * (sqrt(N) / lnN))
    preprocess();

    /// O(T)
    int n;
    while(scanf("%d", &n) == 1)
    {
        printf("%d\n", find_prime_count(n));
    }
    return 0;
}
