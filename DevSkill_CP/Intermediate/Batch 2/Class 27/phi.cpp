#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

ll bm(ll a, ll b, ll mod)
{
    if(!b) return 1LL;
    if(b%2==0)
    {
        ll t = bm(a,b/2,mod)%mod;
        return (t*t) % mod;
    }
    return (a * bm(a,b-1,mod)%mod)%mod;
}

ll modValue(string str,int M)
{
    int res = 0;
    for(auto it : str)
    {
        res = (res * 10 + (it-'0')) % M;
    }
    return res;
}

int main()
{
    for(int i=1;i<=100;i++)
    {
        cout << i << " : " << bm(12,i,23) << endl;
    }
    return 0;
}

