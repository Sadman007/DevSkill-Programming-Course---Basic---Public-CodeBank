#include <bits/stdc++.h>
using namespace std;
#define MAX 200002
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

ll phi[MAX + 5];
ll sum[MAX + 5];

void pre()
{
    for(int i = 0; i < MAX; i++)
        phi[i] = i;
    for(int i = 2; i < MAX; i++)
    {
        if(phi[i] == i)
        {
            for(int j = i; j < MAX; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
    for(int i = 1; i < MAX; i++)
    {
        sum[i] = phi[i] + sum[i - 1];
    }
}

void solve(ll n)
{
    --n;
    int L = 0;
    int R = MAX;
    int M;
    while(L < R)
    {
        M = (L + R) / 2;
        if(sum[M] < n) L = M + 1;
        else R = M;
    }
    ll K;
    if(R) K = n - sum[R - 1];
    else K = n;

    if(R == 0)
    {
        puts("0/1");
        return;
    }
    if(R == 1)
    {
        puts("1/1");
        return;
    }
    int i;
    for(i = 0; ; i++)
    {
        if(__gcd(i, R) == 1) K--;
        if(K == 0) break;
    }
    printf("%d/%d\n", i, R);
    return;
}

int main()
{
    pre();
    ll n;
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0) break;
        solve(n);
    }
    return 0;
}
