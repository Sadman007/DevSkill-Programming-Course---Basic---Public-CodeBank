#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define ll long long
#define MOD 5
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

bool isC[MAX+10];
vector<int>prm;

void sieve()
{
    for(int i=2; i*i<=MAX; i++)
    {
        if(!isC[i])
        {
            for(int j=i*i; j<=MAX; j+=i)
            {
                isC[j] = 1;
            }
        }
    }
    for(int i=2; i<=MAX; i++)
    {
        if(!isC[i])
            prm.push_back(i);
    }
}

int getTotient(int N) 
{
    int res = N;
    for(int i=0; i<(int)prm.size() && prm[i]<=N; i++)
    {
        if(N % prm[i] == 0)
        {
            res*=prm[i]-1;
            res/=prm[i];
        }
    }
    return res;
}

ll expo(ll a,ll b) /// O(logb)
{
    if(b == 0)
        return 1;
    if(b % 2 == 0)
    {
        ll res = expo(a,b/2) % MOD;
        return (res * res)%MOD;
    }
    else
    {
        int res = expo(a,b-1) % MOD;
        return (a * res) % MOD;
    }
}

/**
    11 --> 10
    12 --> 4
    22 --> 10
    5  --> 4
**/

int main()
{
    int N = 50;
    for(int i=1; i<=N; i++)
        cout << i << " " << expo(7,i) << endl;
    return 0;
}
