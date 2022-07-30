#include <bits/stdc++.h>
using namespace std;
#define BASE 129
#define MOD 1000000007
#define MAX_S 1000005

long long h[MAX_S + 5], po[MAX_S + 5];
void generatePrefixHash(string &s)
{
    h[0] = s[0]; // 'c' - 'a' + 1 = 3
    for (int i = 1; i < s.size(); i++)
    {
        h[i] = ((h[i - 1] * BASE) + s[i]) % MOD;
    }
    po[0] = 1; /// po[x] = po[x - 1] * BASE
    for (int i = 1; i <= s.size(); i++)
    {
        po[i] = (po[i - 1] * BASE) % MOD; /// 0 <= po[i - 1] < MOD
    }
}

long long generateHash(string &s)
{
    long long H = 0;
    for (auto c : s)
    {
        H = ((H * BASE) + c) % MOD;
    }
    return H;
}

long long getHash(int L, int R) // hash(s[L...R]) --> s = "aabccd" --> getHash(0, 3)
{
    if (L == 0) return h[R];
    return (h[R] - (h[L - 1] * po[R - L + 1] % MOD) + MOD) % MOD; /// h[R] = 5, h[L - 1] * po[R - L + 1] % MOD = 8
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    generatePrefixHash(s1);
    long long hashOfS2 = generateHash(s2);
    for (int i = 0; i + s2.size() <= s1.size(); i++) /// O(N)
    {
        if (getHash(i, i + s2.size() - 1) == hashOfS2)
        {
            cout << i << "\n";
        }
    }
    return 0;
}
