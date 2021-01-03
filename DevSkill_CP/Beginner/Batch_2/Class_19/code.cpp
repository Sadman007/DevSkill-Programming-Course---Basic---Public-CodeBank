#include <bits/stdc++.h>
using namespace std;

/**
Recursive Primality Testing:

    bool isPrimeR(int i, int N)
    {
        if(N < 2) return false;
        if(i * i > N) return true;
        if(N % i == 0) return false;
        return isPrimeR(i + 1, N);
    }
**/

bool isPrime(int N) /// O(sqrt(N))
{
    if(N < 2) return false;
    for(int i = 2; i * i <= N; i++)
    {
        if(N % i == 0)
            return false;
    }
    return true;
}

vector<int> findDiv(int N)
{
    vector<int>divisors;
    for(int i = 1; i * i <= N; i++)
    {
        if(N % i == 0)
        {
            divisors.push_back(i);
            if(i * i != N) divisors.push_back(N / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long N;
        scanf("%lld", &N);
        long long n = sqrtl(N);
        if(n * n == N && isPrime(n)) puts("YES");
        else puts("NO");
    }
    return 0;
}
