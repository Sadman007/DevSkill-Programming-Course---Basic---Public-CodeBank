#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define MOD 1000000007
#define MAX 200005

int gcd(int a,int b)
{
    int mod;
    while(1)
    {
        mod = a%b;
        if(mod==0) return b;
        a = b;
        b = mod;
    }
}

/// sieve -- O(N*log(logN))
/// naive - loop (1,n)  -- O(N*sqrt(N))
/// primeCheck - O(sqrt(N))
///
/// prime sieve
bool isPrime[100000];
void sievePrime(int n)
{
    memset(isPrime,0,sizeof(isPrime));
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i]==0)
        {
            for(int j=i+i; j<=n; j=j+i)
            {
                isPrime[j] = 1;
            }
        }
    }
}

/// divisors of a number
/// 5 : 1 5
/// 12 : 1 2 3 4 6 12
/// 18 : 1 2 3 6 9 18
/// 16 : 1 2 4 8 16
vector<int>divisors[100000];
void divSieve(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d : ",i);
        for(int j=0;j<(int)divisors[i].size();j++)
        {
            printf("%d ",divisors[i][j]);
        }
        printf("\n");
    }
}

/// sum
int sumDiv[100000];

void divSumSieve(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            sumDiv[j]+=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d : %d\n",i,sumDiv[i]);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    /// O(n*m)
    /// O(sqrt(n*m))
    /// O(log(max(n,m)))
    //cout << gcd(12,30);
    divSieve(50);
    return 0;
}
