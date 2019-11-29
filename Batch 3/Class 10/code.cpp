#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b) /// O(log(min(a,b))
{
    if(a == 0) return b;
    else return gcd(b % a, a);
}

int isPrime(int N) /// O(sqrt(N))
{
    for(int i = 2;i*i <= N;i++)
    {
        if(N % i == 0) return 0;
    }
    return 1;
}

int main()
{
    cout << f(198,963);
    return 0;
}
