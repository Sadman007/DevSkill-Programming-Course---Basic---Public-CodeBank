#include <bits/stdc++.h>
using namespace std;

vector<long long> p1, p2, expo;
const int MOD = 1000000007;
const int BASE = 257;

void generatePrefixHash(string &str, bool is_reversed = false)
{
    vector<long long>pHash(str.size());
    expo.clear();
    expo.resize(str.size());
    expo[0] = 1;
    pHash[0] = str[0];
    for (int i = 1; i < str.size(); i++)
    {
        pHash[i] = (pHash[i - 1] * BASE) + str[i];
        if (pHash[i] >= MOD) pHash[i] %= MOD;
        expo[i] = (expo[i - 1] * BASE) % MOD;
    }
    if (is_reversed) p2 = pHash;
    else p1 = pHash;
}

long long getRangeHash(vector<long long>&pHash, int L, int R)
{
    if (L == 0) return pHash[R];
    auto h1 = pHash[R];
    auto h2 = pHash[L - 1] * expo[R - L + 1];
    if (h2 >= MOD) h2 %= MOD;
    return (h1 - h2 + MOD) % MOD;
}

int findLPS(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        //auto sstr = str.substr(i); /// str[i....]
        //auto rsstr = sstr;
        //reverse(rsstr.begin(), rsstr.end());
        auto h1 = getRangeHash(p1, i, str.size() - 1);
        auto h2 = getRangeHash(p2, 0, str.size() - 1 - i);
        if (h1 == h2) return str.size() - i;
    }
    return -1;
}

string extendToPalindrome(string &str)
{
    int x = findLPS(str);
    int N = str.size();
    string pref = str.substr(0, N - x);
    reverse(pref.begin(), pref.end());
    return str + pref;
}

int main()
{
    string str;
    while(cin >> str)
    {
        string rstr = str;
        reverse(rstr.begin(), rstr.end());
        generatePrefixHash(str); /// populates p1
        generatePrefixHash(rstr, true); /// populates p2
        cout << extendToPalindrome(str) << "\n";
    }
    return 0;
}
