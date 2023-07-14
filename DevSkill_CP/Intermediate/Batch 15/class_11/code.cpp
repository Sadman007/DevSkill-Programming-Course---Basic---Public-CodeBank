#include <bits/stdc++.h>
using namespace std;

vector<bool> marked;
/// O(nloglogn)
void generatePrimes(int n)
{
    marked.clear();
    marked.resize(n + 1, 0);
    marked[0] = marked[1] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (marked[i] == 0) /// i is not marked. so mark all the multiples of i.
        {
            for (int mult = i * i; mult <= n; mult += i)
            {
                marked[mult] = 1;
            }
        }
    }
}

vector<int> divs[1000005];
void generateDivisors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int mult = i; mult <= n; mult += i)
        {
            divs[mult].push_back(i);
        }
    }
}

const int MOD = 11;
long long bM(int a, int b)
{
    if (b == 0) return 1;
    if (b % 2 == 0)
    {
        auto t = bM(a, b / 2) % MOD;
        return (t * t) % MOD;
    }
    return (a * bM(a, b - 1)) % MOD;
}

int main()
{
    // int n = 1000000;
    // generatePrimes(n);
    // generateDivisors(n);
    // for (auto num : divs[19]) cout << num << " ";
    for (int i = 2; i <= 100; i++)
    {
        cout << bM(7, i) << "\n";
    }
    return 0;
}
