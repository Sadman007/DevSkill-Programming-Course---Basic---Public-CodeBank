#include <iostream>
using namespace std;
#define MAX 1000000
int phi[MAX + 5];

void sieve(int n) /// O(nloglogn)
{
    for(int i = 1; i <= n; i++)
        phi[i] = i;

    for(int i = 2; i <= n; i++)
    {
        if(phi[i] == i)
        {
            for(int j = i; j <= n; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int bigmod(int a, int b, int m)
{
    if(b == 0) return 1;
    if(b % 2 == 0)
    {
        int t = bigmod(a, b / 2, m) % m;
        return (t * t) % m;
    }
    return (a * bigmod(a, b - 1, m)) % m;
}

int main()
{
    for(int i = 1; i <= 100; i++)
    {
        printf("(7 ^ %d) % 19 = %d\n", i, bigmod(7, i, 19));
        getchar();
    }
    return 0;
}

