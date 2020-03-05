#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")
#define all(v) v.begin(),v.end()

/**
    1) number ta borgo hobe
    2) K er value 2500 er beshi hobena

**/

bool isComp[MAX+5];
vector<int>primes;

vector<ll>divisors[5000];

void sieve() /// NlogN
{
    for(int i = 2; i * i <= MAX; i++) /// NloglogN
    {
        if(isComp[i] == false)
        {
            for(int j = i * i; j <= MAX; j+=i)
            {
                isComp[j] = true;
            }
        }
    }

    for(int i = 2;i <= MAX;i++) /// N
    {
        if(isComp[i] == false) primes.push_back(i);
    }

    for(int num = 1; num <= MAX; num++) /// NlogN
    {
        int nod = 1;
        int N = num;
        for(int j = 0 ; j < primes.size() && primes[j]*primes[j] <= N; j++) /// logN
        {
            if(N % primes[j] == 0)
            {
                int alpha = 0;
                while(N % primes[j] == 0)
                {
                    N/=primes[j];
                    alpha++;
                }
                nod*=(2*alpha + 1);
            }
        }
        if(N > 1) nod*=3;
        divisors[nod].push_back(1LL * num * num);
    }
}

int main() /// NlogN
{
    sieve(); /// NlogN
    int t;
    scanf("%d", &t);
    while(t--) /// TlogN
    {
        ll low,high,K;
        scanf("%lld %lld %lld",&K,&low,&high);
        if(K > 2500) printf("0\n");
        else printf("%d\n",upper_bound(all(divisors[K]),high) - lower_bound(all(divisors[K]),low)); /// logN
    }
    return 0;
}
