#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define ll long long
#define MOD 1000000007
#define bs 191

char str[MAX + 5], T[MAX + 5];
ll H[MAX + 5], po[MAX + 5];

void pre() /// O(N)
{
    int n = strlen(str);
    H[0] = str[0];
    for(int i = 1; i < n; i++)
    {
        H[i] = ((bs * H[i - 1]) % MOD + str[i]);
        if(H[i] > MOD)
            H[i] %= MOD;
    }
}

ll getHash(int L, int R) /// O(1)
{
    if(L == 0)
        return H[R];
    ll left = H[R];
    ll right = (H[L - 1] * po[R - L + 1]);
    if(right > MOD)
        right %= MOD;
    return (left - right + MOD) % MOD;
}

ll get_T_hash()
{
    ll h = 0;
    int nt = strlen(T);
    for(int i = 0; i < nt; i++)
    {
        h = ((h * bs) + T[i]);
        if(h > MOD)
            h %= MOD;
    }
    return (h + MOD) % MOD;
}
