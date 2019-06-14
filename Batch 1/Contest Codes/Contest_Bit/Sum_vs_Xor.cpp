#include <bits/stdc++.h>
using namespace std;

void bin(int n)
{
    if(n==0) return;
    bin(n/2);
    printf("%d",n%2);
}

bool valid(int a,int b)
{
    int sum = a+b;
    int x = a^b;
    return sum==x;
}

void bruteForce()
{
    long long n;
    scanf("%lld",&n);
    bin(n);
    puts("");
    for(long long i=1;i<=n;i++)
    {
        if(valid(i,n))
        {
            printf("Value %d: ",i);
            bin(i);
            puts("");
        }
    }
}

int main()
{
    ///bruteforce has not been called.
    long long n;
    scanf("%lld",&n);
    int cnt_zero_bit = log2(n)+1 - __builtin_popcountll(n);
    printf("%lld\n",1LL<<cnt_zero_bit);
    return 0;
}

/**
10100

00000
00001
00010
00011
01000
01001
01010
01011
**/
