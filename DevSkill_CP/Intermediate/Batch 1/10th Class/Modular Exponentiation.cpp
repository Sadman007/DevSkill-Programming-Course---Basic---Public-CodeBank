#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

ll bm(ll a,ll b)
{
    if(b==0) return 1;
    if(b%2==0)
    {
        ll tmp = bm(a,b/2)%MOD;
        return (tmp*tmp)%MOD;
    }
    else return (a*bm(a,b-1))%MOD;
}

int main()
{
    ll a,b;
    cin >> a >> b;
    cout << bm(a,b) << "\n";
    return 0;
}