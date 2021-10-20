#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000005
#define BASE 257
#define MOD 1000000007

ll prefix_hash[MAX + 5];
ll po[MAX + 5]; /// po[R - L + 1] = BASE ^ (R - L + 1)

void pre(string &str)
{
    po[0] = 1; /// base ^ 0
    for (int i = 1; i <= str.size(); i++)
    {
        po[i] = (po[i - 1] * BASE) % MOD; /// a ^ b = (a ^ (b - 1)) * a ---> 3^7 = 3^6 * 3
    }
    prefix_hash[0] = str[0];
    for (int i = 1; i < str.size(); i++)
    {
        prefix_hash[i] = ((prefix_hash[i - 1] * BASE) + str[i]) % MOD;
    }
}

ll get_hash(int L, int R) /// O(1)
{
    if (!L) return prefix_hash[R];
    return (prefix_hash[R] - (prefix_hash[L - 1] * po[R - L + 1] % MOD) + MOD) % MOD; /// pH[R] - (pH[L - 1] * B^(R-L+1))
}

int main()
{
    string s, t;
    cin >> s >> t;
    pre(s);
    ll hash_of_t = 0;
    for (auto c : t)
    {
        hash_of_t = ((hash_of_t * BASE) + c) % MOD;
    }
    for (int i = 0; i + (int)t.size() <= (int)s.size(); i++) /// O(|S|)
    {
        ll range_hash = get_hash(i, i + (int)t.size() - 1); /// [i, i + t.size() - 1]
        if (range_hash == hash_of_t)
        {
            cout << i << "\n";
        }
    }

    return 0;
}
