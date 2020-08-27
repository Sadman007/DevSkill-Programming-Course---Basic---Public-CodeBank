#include <bits/stdc++.h>
using namespace std;
#define MAX 10000005
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

bool prm[MAX + 5];
vector<int>vprm;
ll phi[100000 + 10], num[100000 + 10];

void sieve()
{
    for(int i = 2; i * i <= MAX; i++)
    {
        if(prm[i] == 0)
        {
            for(int j = i * i; j <= MAX; j += i)
            {
                prm[j] = 1;
            }
        }
    }
    for(int i = 2; i <= MAX; i++)
    {
        if(prm[i] == 0) vprm.push_back(i);
    }
}

void seg_sieve(ll L, ll R)
{
    for(ll i = L; i <= R; i++)
    {
        phi[i - L] = num[i - L] = i;
    }
    for(int i = 0; i < (int)vprm.size() && vprm[i] <= R / vprm[i]; i++)
    {
        ll multiple = vprm[i] * vprm[i];
        if(multiple < L)
            multiple = ((L + vprm[i] - 1) / vprm[i]) * vprm[i];
        while(multiple <= R)
        {
            while(num[multiple - L] % vprm[i] == 0)
            {
                num[multiple - L] /= vprm[i];
            }
            phi[multiple - L] -= phi[multiple - L] / vprm[i];

            multiple += vprm[i];
        }
    }
    for(ll i = L; i <= R; i++)
    {
        if(num[i - L] != 1)
            phi[i - L] -= phi[i - L] / num[i - L];
        printf("%lld\n", phi[i - L]);
    }
}

int main()
{
    sieve();
    ll L, R;
    scanf("%lld %lld", &L, &R);
    seg_sieve(L, R);
    return 0;
}
