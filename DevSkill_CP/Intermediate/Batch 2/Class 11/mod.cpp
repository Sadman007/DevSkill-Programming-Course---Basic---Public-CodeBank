#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 45

ll modExpo(ll a,ll b)
{
    if(b == 0) return 1;

    if(b%2==0)
    {
        ll res = modExpo(a,b/2)%M;
        return (res*res)%M;
    }

    if(b%2==1)
    {
        return (a%M*modExpo(a,b-1)%M)%M;
    }
}

ll f(int n)
{
    if(n==0) return 1;
    else return n*f(n-1);
}


int main()
{
    cout << f(5);
    return 0;
}
