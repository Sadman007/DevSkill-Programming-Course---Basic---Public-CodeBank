#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

ll russian_peasant(ll a, ll b, ll mod)
{
    ll res = 0;
    while(b > 0)
    {
        if(b % 2 == 1) res = (res + a) % mod;

        a = (a << 1) % mod;
        b = (b >> 1);
    }
    return res;
}

int main()
{
    cout << russian_peasant(111222333444555666LL,111222333444555666LL,111222333444555777LL);
    return 0;
}
