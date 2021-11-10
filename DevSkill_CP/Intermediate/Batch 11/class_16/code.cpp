#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000

int pr[MAX + 5], value[MAX + 5];
vector<int> primes;
bool isComp[MAX + 5];

int find_parent(int u) /// 5 -> 4 -> 3 -> 2 -> [1]
{
    if (u == pr[u]) return u;
    return pr[u] = find_parent(pr[u]);
}

void unite(int u, int v)
{
    int pu = find_parent(u);
    int pv = find_parent(v);
    if (pu != pv)
        pr[pu] = pv;
}

void sieve()
{
    for (int i = 2; i * i <= MAX; i++)
    {
        if(!isComp[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isComp[j] = 1;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= MAX; i += 2)
    {
        if (!isComp[i]) primes.push_back(i);
    }
}

vector<int> getPrimeList(int value)
{
    vector<int> uniquePrimes;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= value; i++)
    {
        if (value % primes[i] == 0)
        {
            uniquePrimes.push_back(primes[i]);
            while(value % primes[i] == 0)
            {
                value /= primes[i];
            }
        }
    }
    if (value > 1) uniquePrimes.push_back(value);
    return uniquePrimes;
}

int main()
{
    // freopen("out.txt", "w", stdout);
    sieve();
    int n, T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        for (int i = 1; i <= MAX; i++)
            pr[i] = i;
        scanf("%d", &n);
        int oneCount = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &value[i]);
            auto upList = getPrimeList(value[i]);
            for (auto u : upList) /// value = 12, upList = {2, 3}
            {
                unite(u, value[i]);
            }
            oneCount += value[i] == 1;
        }
        unordered_set<int> uniqueGroups;
        for (int i = 0; i < n; i++)
        {
            if (value[i] > 1)
            {
                uniqueGroups.insert(find_parent(find_parent(value[i])));
            }
        }
        printf("Case %d: %d\n", cs++, (int)uniqueGroups.size() + oneCount);
    }
    return 0;
}


