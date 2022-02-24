#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000

bool comp[MAX + 5];
vector<int>prm;
ll ans[MAX + 5];

void sieve()
{
    for(int i = 2; i * i <= MAX; i++)
    {
        if(!comp[i])
        {
            for(int j = i * i; j <= MAX; j += i)
            {
                comp[j] = true;
            }
        }
    }
    for(int i = 2; i <= MAX; i++)
    {
        if(!comp[i])
            prm.push_back(i);
    }
}

/// 120 = (2^3) * (3^1) * (5^1)
/// 38 = (2^1) * (19^1)

/// O(sqrt(N))
int primeCount(int n)
{
    if(comp[n] == 0) return 1;
    int cnt = 0;
    /// 2,3,4,5,6
    for(int i = 0; i < prm.size() && prm[i] * prm[i] <= n; i++)
    {
        if(n % prm[i] == 0)
        {
            while(n % prm[i] == 0)
            {
                n /= prm[i];
                cnt++;
            }
        }
    }
    if(n > 1) cnt++;
    return cnt;
}

/// O(MAX * H(MAX)) = O(MAX * log2(MAX))
void preCalculate()
{
    ans[2] = 1;
    for(int i = 3; i <= MAX; i++)
    {
        ans[i] = ans[i - 1] + primeCount(i);
        /// ans[3] = ans[2] + pC(3)
    }
}

int main()
{
    sieve();
    preCalculate();
    int n;
    while(scanf("%d", &n) == 1)
    {
        printf("%lld\n", ans[n]);
    }
    return 0;
}
