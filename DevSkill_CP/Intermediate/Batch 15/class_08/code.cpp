#include <bits/stdc++.h>
using namespace std;

char temp[1000005];

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

long long generateHash(string &B)
{
    long long H = 0;
    for (auto c : B)
    {
        H = (H * BASE) + c;
        if (H >= MOD) H %= MOD;
    }
    return H;
}

int findOccurrence(string &A, string &B)
{
    generatePrefixHash(A);
    auto hB = generateHash(B);
    int cnt = 0;

    for (int i = 0; i + B.size() <= A.size(); i++)
    {
        auto rangeHash = getRangeHash(i, i + B.size() - 1);
        cnt += rangeHash == hB;
    }

    return cnt;
}

int main()
{
    int T, cs = 1;
    string A, B;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", temp);
        A = temp;
        scanf("%s", temp);
        B = temp;
        printf("Case %d: %d\n", cs, findOccurrence(A, B));
    }
    return 0;
}
