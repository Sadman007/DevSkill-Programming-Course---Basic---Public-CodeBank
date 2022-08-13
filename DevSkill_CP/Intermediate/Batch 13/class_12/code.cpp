#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;

vector<int> generatePrimes(int N) /// O(Nlog(log(N)))
{
    // composite[4] = 0; 4 is not composite, so 4 is prime.
    vector<bool> composite(N + 1, false);
    vector<int> primes;
    composite[1] = true;
    for (int i = 2; i * i <= N; i++)
    {
        if (composite[i] == 0) // `i` is prime
        {
            for (int j = i * i; j <= N; j += i)
            {
                composite[j] = true;
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (composite[i] == 0)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

vector<int> divs[MAX + 5];

/// TC/MC: O(N * log(N))
void generateDivisors(int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            divs[j].push_back(i);
        }
    }
}

int main()
{
    // auto primes = generatePrimes(100);
    generateDivisors(MAX);
    int mx = 0, sum = 0;
    for (int i = 1; i <= MAX; i++)
    {
        // mx = max(mx, (int)divs[i].size());
        sum += divs[i].size();
    }
    cout << 1.00 * sum / MAX;
    return 0;
}
