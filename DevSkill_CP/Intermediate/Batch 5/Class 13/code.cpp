#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
    1) (a1*a2*....*ak) % M = ((a1 % M) * (a2 % M) * (a3 % M) * .... * (ak % M)) % M
    2) (A+B) % M = ((A%M) + (B%M))%M
    3) (A-B) % M = ((A%M) - (B%M))%M
    4) (A^B) % M = ((A%M)^B) % M
**/
/**
    sqrt(N) -- > O(logN) -- > float
    sqrtl(N) -- > O(logN) -- > double
    log(N) -- > O(logN) -- > float
**/
ll getMod(ll a,ll b,ll MOD) /// O(B)
{
    ll res = 1;
    while(b--)
    {
        res = (res * a) % MOD;
    }
    return res;
}

int main()
{
    cout << getMod(31,97,123);
    return 0;
}
