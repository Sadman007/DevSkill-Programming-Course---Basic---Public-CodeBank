#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long

bool isComp[MAX + 5];
vector<int>prm;
vector<ll>divCount[1330];

void sieve()
{
    for(int i = 2; i * i <= MAX; i++)
    {
        if(!isComp[i])
        {
            for(int j = i * i; j <= MAX; j += i)
            {
                isComp[j] = 1;
            }
        }
    }
    for(int i = 2; i <= MAX; i++)
    {
        if(!isComp[i]) prm.push_back(i);
    }
}

int cnt_div_sqr(ll N) /// returns COD(N^2) , O(sqrt(N / ln(N)))
{
    int res = 1;

    for(int i = 0; i < prm.size() && prm[i] * prm[i] <= N; i++)
    {
        if(N % prm[i] == 0)
        {
            int cnt = 0;
            while(N % prm[i] == 0)
            {
                N /= prm[i];
                cnt++;
            }
            res = (res * ((2 * cnt) + 1));
        }
    }
    if(N > 1) res *= 3;
    return res;
}

int main() /// O(N*log^2(N) + T*logN)
{
    sieve();

    for(int i = 0; i <= MAX; i++)
        divCount[cnt_div_sqr(i)].push_back(1LL * i * i);

    int T;
    scanf("%d", &T);
    while(T--)
    {
        ll L, R, K;
        scanf("%lld %lld %lld", &K, &L, &R);
        if(K > 1323) puts("0");
        else
        {
            int ans = upper_bound(divCount[K].begin(), divCount[K].end(), R) - lower_bound(divCount[K].begin(), divCount[K].end(), L);
            printf("%d\n", ans);
        }
    }
    return 0;
}
