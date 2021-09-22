#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

bool is_composite[MAX + 5]; /// this is initialized with 0.
vector<int> primes, divisors[MAX + 5];

void sieve(int n)
{
    int cnt = 0;
    for (int pivot = 2; pivot * pivot <= n; pivot++) /// O(sqrt(n))
    {
        if (!is_composite[pivot]) /// i is a prime.
        {
            for (int multiple = pivot * pivot; multiple <= n; multiple += pivot)
            {
                cnt++;
                is_composite[multiple] = true;
            }
        }
    }
    cout << cnt << "\n";
    for (int i = 2; i <= n; i++)
    {
        if (!is_composite[i])
        {
            primes.push_back(i);
        }
    }
}

void div_sieve(int n) /// O(nlogn)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}

int main()
{
    //sieve(MAX);
    //cout << primes.size() << "\n";
    div_sieve(100);
    for (auto it : divisors[12])
        cout << it << " ";
    return 0;
}
