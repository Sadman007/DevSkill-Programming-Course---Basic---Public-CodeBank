#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) /// O(sqrt(N)) ---> N = 10^16
{
    if(n<2) return 0;
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i == 0) return 0;
    }
    return 1;
}

bool NotPrime[10000100];

void sieve(int N) /// 1 theke N porjonto prime number generate korte hobe
{
    /**
        1 theke 10^6
        O(10^6 * 10^3) = O(10^9) = 10s
        N*sqrt(N)
    for(int i=1;i<=N;i++) /// O(N)
    {
        if(isPrime(i)) cout << i << " "; /// O(sqrt(N))
    }
    cout << endl;
    **/
    NotPrime[1] = 1;
    for(int i = 2;i<=N;i++)
    {
        if(NotPrime[i] == 0)
        {
            for(int j = i+i;j<=N;j+=i) /// i = 2 , j = 2+2 = 4
            {
                NotPrime[j] = 1;
            }
        }
    }
    /**
    1 0 0 1 0 1 0 1 1 1 0 1 0 1 1 1 0 1 0 1 1 1 0 1 1
    **/
}

int dv[100000],sum[100000];
vector<int>divisors[100000];

void divSieve(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            dv[j]++;
        }
    }
}

void divSumSieve(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            sum[j]+=i;
        }
    }
}

void divCalculate(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
}

int main()
{
    divCalculate(30);
    for(auto it : divisors[30])
    {
        cout << it << " ";
    }
    return 0;
}
