#include <bits/stdc++.h>
using namespace std;

void STRING_TEST()
{
    vector<string> vstr;
    int T;
    cin >> T;
    cin.ignore();
    while(T--)
    {
        string str;
        getline(cin, str);
        vstr.push_back(str);
    }
    for (int i = 0; i < vstr.size(); i++)
    {
        // cout << vstr[i] << "\n";
        for (int j = 0; j < vstr[i].size(); j++)
        {
            cout << vstr[i][j];
        }
        cout << "\n";
    }
}

bool isSubstrEqual(string &s1, string &s2, int st_idx, int len)
{
    return s1.substr(st_idx, len) == s2.substr(st_idx, len);
}

vector<long long> pHash, expo;
const int MOD = 1000000007;
const int BASE = 257;

void generatePrefixHash(string &str)
{
    pHash.clear();
    expo.clear();
    pHash.resize(str.size());
    expo.resize(str.size());
    expo[0] = 1;
    pHash[0] = str[0];
    for (int i = 1; i < str.size(); i++)
    {
        pHash[i] = (pHash[i - 1] * BASE) + str[i];
        if (pHash[i] >= MOD) pHash[i] %= MOD;

        expo[i] = (expo[i - 1] * BASE) % MOD;
    }
}

/// TC: O(1)
long long getRangeHash(int L, int R)
{
    if (L == 0) return pHash[R];
    auto h1 = pHash[R];
    auto h2 = pHash[L - 1] * expo[R - L + 1];
    if (h2 >= MOD) h2 %= MOD;
    return (h1 - h2 + MOD) % MOD;
}

int main()
{
    string s1 = "abcdeabcd";
    generatePrefixHash(s1);
    for (int i = 0; i < s1.size(); i++)
    {
        cout << pHash[i] << "\n";
    }
    cout << getRangeHash(0, 2) << "\n";
    cout << getRangeHash(5, 7) << "\n";
    return 0;
}
