#include <bits/stdc++.h>
using namespace std;

/// prime sieve
bool isPrime[1000010];

void primeSieve(int n)
{
    memset(isPrime,0,sizeof(isPrime));
    for(int i=2;i<=n;i++)
    {
        if(!isPrime[i])
        {
            for(int j=i+i;j<=n;j+=i)
            {
                isPrime[j] = 1;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(!isPrime[i]) printf("%d ",i);
    }
    puts(""); /// this line prints a new line,nothing fancy!
    return;
}

/// divisor sieve
vector<int>divisors[1000010];
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
        for(auto it : divisors[i])
        {
            printf("%d ",it);
        }
        puts("");
    }
    return;
}

/// sum of divisor sieve
int sod[1000010];
void sodSieve(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {
            sod[j]+=i;
        }
    }
    for(int i=1; i<=n; i++)
    {
        printf("%d : %d\n",i,sod[i]);
    }
    puts("");
    return;
}
int main()
{
    //primeSieve(100);
    //divSieve(20);
    sodSieve(1000000);
    return 0;
}

