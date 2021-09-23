#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000

bool is_composite[MAX + 5];
vector<int>primes;

void sieve()
{
    for (int i = 2; i * i <= MAX; i++)
    {
        if (!is_composite[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                is_composite[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAX; i++)
    {
        if(!is_composite[i])
        {
            primes.push_back(i);
        }
    }
}

/// O(sqrt(N))
int get_div_count(ll num)
{
    int cnt = 1;
    for (ll i = 0; i < primes.size() && primes[i] * primes[i] <= num; i++) /// 2^3 * 3^2 = 8 * 9 = 72 --> 9
    {
        if (num % primes[i] == 0) /// i is a divisor of num.
        {
            int pcnt = 0;
            while (num % primes[i] == 0)
            {
                num /= primes[i];
                pcnt++;
            }
            cnt *= (pcnt + 1);
        }
    }
    if (num > 1) cnt *= 2;
    return cnt;
}

int main()
{
    sieve();
    cout << get_div_count(99999999999899999LL) << "\n";
    return 0;
}

/// 2^3 * 5^1 * 7^1 * 11^2 = 280 / 2^3 = 35
