#include <bits/stdc++.h>
using namespace std;
#define MAX 10010
#define ll long long
ll n,m,arr[MAX];

bool cmp(ll a,ll b)
{
    ll ma = a % m;
    ll mb = b % m;
    if(ma == mb)
    {
        if(abs(a)%2 == abs(b)%2)
        {
            if(abs(a)%2) return a>b;
            return b>a;
        }
        else if(abs(a)%2 == 1) return 1;
        else return 0;
    }
    return ma < mb;
}

int main()
{
    //freopen("out.txt","w",stdout);
    while(scanf("%lld%lld",&n,&m) == 2)
    {
        printf("%lld %lld\n",n,m);
        if(n == 0 && m == 0) break;
        for(int i=0; i<n; i++)
            scanf("%lld",&arr[i]);
        sort(arr,arr+n,cmp);
        for(int i=0; i<n; i++)
        {
            printf("%lld\n",arr[i]);
        }
    }
    return 0;
}
