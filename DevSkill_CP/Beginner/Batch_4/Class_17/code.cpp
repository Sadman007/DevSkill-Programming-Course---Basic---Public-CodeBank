#include <bits/stdc++.h>
using namespace std;
#define MAX 100000000
bool isComp[MAX + 5]; /// isComp = 0

bool isPrime(int num)
{
    if(num < 2) return 0;
    for(int i = 2; i * i <= num; i++) /// i * i <= num
    {
        if(num % i == 0) return 0;
    }
    return 1;
}

void sieve(int n) /// O(nlogn) ==> O(n * log(log(n)))
{
    isComp[1] = 1;
    for(int i = 2; i * i <= n; i++)
    {
        if(isComp[i] == 0) /// i is prime
        {
            for(int j = i * i; j <= n; j += i)
            {
                isComp[j] = 1;
            }
        }
    }
}

int main()
{
    sieve(MAX);
    return 0;
}
