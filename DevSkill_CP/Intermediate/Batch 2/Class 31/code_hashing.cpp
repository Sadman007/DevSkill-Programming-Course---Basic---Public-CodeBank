#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define BASE 31
#define MAX 1000005

char A[MAX+5], B[MAX+5];
ll h[MAX+5], po[MAX+5];
int la,lb;

void pre()
{
    po[0] = 1;
    for(int i = 1; i<MAX; i++)
    {
        po[i] = (po[i-1] * BASE) % MOD;
    }
}

void preprocess() /// O(|B|)
{
    h[0] = B[0]-'a'+1;
    for(int i = 1 ; i < lb; i++)
    {
        h[i] = (h[i - 1] * BASE + (B[i] - 'a' + 1)) % MOD;
    }
}

ll getHash(int L, int R) /// O(1)
{
    if(L == 0)
        return h[R];
    ll res = (h[R] - (h[L - 1] * po[R-L+1]) % MOD + MOD + MOD) % MOD;
    return res;
}

ll makeHash()
{
    ll h = 0;
    for(int i = 0; i<la; i++)
    {
        h = ((h * BASE) % MOD + (A[i] - 'a' + 1)) % MOD;
    }
    return h;
}

int main()
{
    pre();
    int t, cs=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s %s", A, B); /// abc

        la = strlen(A);
        lb = strlen(B);
        preprocess(); /// O(B)

        ll hA = makeHash(); /// O(A)

        int cnt = 0;

        for(int i=0; i<lb; i++) /// O(B)
        {
            if(i+la-1 >= lb) break;
            if(getHash(i,i+la-1) == hA) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
