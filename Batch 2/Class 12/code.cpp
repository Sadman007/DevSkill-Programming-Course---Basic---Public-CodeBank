#include <bits/stdc++.h>
using namespace std;

bitset<110>isPrime;
/// isPrime = 00000
///int isPrime[110];

void sieve(int N)
{
    ///memset(isPrime,0,sizeof isPrime);
    isPrime.reset();
    for(int i=2;i*i<=N;i++)
    {
        if(isPrime[i] == 0)
        {
            for(int j = i*i;j<=N;j+=i)
            {
                isPrime[j] = 1;
            }
        }
    }
}

int main()
{
    sieve(100);
    for(int i=2;i<=100;i++)
    {
        cout << i << " " << isPrime[i] << "\n";
    }
    return 0;
}
