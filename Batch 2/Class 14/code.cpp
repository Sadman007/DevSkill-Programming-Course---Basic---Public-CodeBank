#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;

/**
    aabbaa
    O(N/2) --> O(N)
**/

bool palindrome(int L,int R)
{
    if(L>=R) return 1;
    if(s[L]!=s[R]) return 0;
    return palindrome(L+1,R-1);
}

int sum(int N)
{
    if(N == 0) return 0;
    return N + sum(N-1);
}

/**
    1 + 2 + 3 + ... + N = ?
    1^1 + 2^2 + 3^3 + .... + N^N = ?
    1^1 + 2^2 + 3^3 + .... + (N-1)^(N-1) + N^N = ?
**/

ll po(ll a,ll b)
{
    ll s = 1;
    while(b--) s*=a;
    return s;
}

ll seriesSum(int N)
{
    if(N == 0) return 0;
    return po(N,N) + seriesSum(N-1);
}

ll fib(ll n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main()
{
    cout << seriesSum(3);
    return 0;
}
