#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define MOD 1000000007
#define R 1
#define G 2
#define B 3

char str[MAX + 5];
int n, dp[MAX + 5][4];
unordered_map<char, int> ump;

int f(int pos, int last)
{
    if (pos >= n) return 1;
    int &ret = dp[pos][last];
    if (ret != -1) return ret;
    ret = 0;

    if (str[pos] == 'W')
    {
        if (str[pos + 1] != 'R' && last != R) ret = (ret + f(pos + 1, R)) % MOD;
        if (str[pos + 1] != 'G' && last != G) ret = (ret + f(pos + 1, G)) % MOD;
        if (str[pos + 1] != 'B' && last != B) ret = (ret + f(pos + 1, B)) % MOD;
    }
    else
    {
        ret = f(pos + 1, ump[str[pos]]) % MOD;
    }
    return ret;
}

int main()
{
    ump['R'] = R;
    ump['G'] = G;
    ump['B'] = B;

    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", str);
        n = strlen(str);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", cs++, f(0, 0));
    }
    return 0;
}
