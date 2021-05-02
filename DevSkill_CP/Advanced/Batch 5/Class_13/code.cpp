#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000
#define base 26
ll h[MAX + 5], po[MAX + 5];

void preprocess(string &s)
{
    h[0] = s[0] - 'a';
    po[0] = 1;
    for(int i = 1; i < s.size(); i++)
    {
        h[i] = (h[i - 1] * base) % MOD + (s[i] - 'a');
        h[i] %= MOD;
        po[i] = (po[i - 1] * base) % MOD;
    }
}

ll getHash(int L, int R)
{
    if(!L) return h[R];
    ll rangeHash = (h[R] - (h[L - 1] * po[R - L + 1] % MOD) + MOD) % MOD;
    return rangeHash;
}

int main()
{
    string s;
    cin >> s;
    preprocess(s);
    while(1)
    {
        int L, R;
        cin >> L >> R;
        cout << getHash(L, R) << endl;
    }
    return 0;
}

