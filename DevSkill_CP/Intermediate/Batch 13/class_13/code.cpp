#include<bits/stdc++.h>
using namespace std;

const int MX = 1e7;
bool isPrime[MX + 5];
vector<long long> prime;

void sieve()
{
    isPrime[1] = 1;
    for(int i = 2; i*i <= MX; i++)
    {
        if(isPrime[i] == 0)
        {
            for(int j = i*i ; j<=MX; j+=i)
                isPrime[j] = 1;
        }
    }
    prime.push_back(2);
    for(long long i=3; i<=MX; i+=2)
    {
        if(isPrime[i]==0) prime.push_back(i);
    }
}

long long findMaxPrimeFactor(long long n)
{
    if (n < 0) n *= -1;
    long long maxPrimeFactor = -1, nn = n;
    int pCnt = 0;
    for(int i = 0; i < prime.size() && prime[i] <= (n / prime[i]); i++)
    {
        if(n % prime[i] == 0)
        {
            while(n % prime[i] == 0)
            {
                n /= prime[i];
            }
            maxPrimeFactor = max(maxPrimeFactor, prime[i]);
            pCnt++;
        }
    }
    if(n > 1)
    {
        maxPrimeFactor = max(maxPrimeFactor, n);
        pCnt++;
    }
    return (maxPrimeFactor == nn || pCnt == 1) ? -1 : maxPrimeFactor;
}

int main()
{
    sieve();
    long long n;
    while(scanf("%lld",&n) == 1 && n != 0)
    {
        printf("%lld\n",findMaxPrimeFactor(n));
    }
    return 0;
}
