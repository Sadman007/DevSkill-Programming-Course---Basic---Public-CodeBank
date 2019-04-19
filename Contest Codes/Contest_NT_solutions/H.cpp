#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define MOD 1000000007
#define MAX 100005

vector<ll>dv[2500];
vector<int>prm;
bitset<MAX+5>isP;

void sieve()
{
    isP.reset();
    for(int i=2;i*i<=MAX;i++)
    {
        if(!isP[i])
        {
            for(int j=i+i;j<=MAX;j+=i)
            {
                isP[j]=1;
            }
        }
    }
    isP[1] = 1;
    for(int i=2;i<=MAX;i++)
    {
        if(!isP[i]) prm.pb(i);
    }
}
int cntDiv(int val)
{
    if(val<MAX && isP[val]==0) return 3;
    int ans = 1;
    for(int i=0;i<(int)prm.size() && prm[i]*prm[i]<=val;i++)
    {
        if(val<MAX && isP[val]==0)
        {
            ans*=3;
            return ans;
        }
        if(val%prm[i]==0)
        {
            int cnt = 0;
            while(val%prm[i]==0)
            {
                val/=prm[i];
                ++cnt;
            }
            ans*=(2*cnt)+1;
        }
    }
    if(val>1) ans*=3;
    return ans;
}
void doo()
{
    for(int i=1;i<=MAX;i++)
    {
        dv[cntDiv(i)].push_back(1LL*i*i);
    }
}


int main()
{
    sieve();
    doo();
    int t;
    ll L,R,K;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&K,&L,&R);
        if(K>2340) puts("0");
        else
        {
            printf("%d\n",upper_bound(dv[K].begin(),dv[K].end(),R)-lower_bound(dv[K].begin(),dv[K].end(),L));
        }
    }
    return 0;
}
