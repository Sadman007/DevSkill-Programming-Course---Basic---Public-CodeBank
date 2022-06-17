#include <bits/stdc++.h>
using namespace std;
vector<int>primes;
vector<int> numbers;

bool isPrime(int n)
{
    /// LOGIC HERE
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

void generatePrimes(int L, int R)
{
    for (int i = L; i <= R; i++)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }
}

void gen()
{
    generatePrimes(1, 100);
    for (auto prime : primes)
        cout << prime << "\n";
}

int div_count[1010];

int countDivisor(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
        }
    }
    return cnt;
}

/// O(1)
bool isSmaller(int x, int y) /// (x < y) -> true, false
{
    int div_cnt_x = div_count[x];
    int div_cnt_y = div_count[y];
    if (div_cnt_x < div_cnt_y) return true;
    if (div_cnt_x > div_cnt_y) return false;
    return x > y;
}

void precalculate()
{
    for (int i = 1; i <= 1000; i++)
    {
        numbers.push_back(i);
        div_count[i] = countDivisor(i);
    }
    sort(numbers.begin(), numbers.end(), isSmaller);
}

int main()
{
    precalculate();
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        int pos;
        scanf("%d", &pos);
        printf("Case %d: %d\n", cs++, numbers[pos - 1]);
    }
    return 0;
}
