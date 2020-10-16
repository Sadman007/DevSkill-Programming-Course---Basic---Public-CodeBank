#include <bits/stdc++.h>
using namespace std;

string s, t;
int n;
int dp[201][201][201];

int f(int pos, int rem, int tot)
{
    if(pos >= n) return 0;
    int &ret = dp[pos][rem][tot];
    if(ret != -1) return ret;

    ret = 0;
    if(s[pos] == t[1])
    {
        ret = tot + f(pos + 1, rem, tot + (t[0] == t[1]));
        if(rem)
            ret = max(ret , f(pos + 1, rem - 1, tot + 1));
    }
    else if(s[pos] == t[0])
    {
        ret = (t[0] == t[1] ? tot : 0) + f(pos + 1, rem, tot + 1);
        if(rem)
            ret = max(ret , tot + f(pos + 1, rem - 1, tot + (t[0] == t[1])));
    }
    else
    {
        ret = f(pos + 1, rem, tot);
        if(rem)
        {
            ret = max(ret, f(pos + 1, rem - 1, tot + 1));
            ret = max(ret, tot + f(pos + 1, rem - 1, tot + (t[0] == t[1])));
        }
    }
    return ret;
}


int main()
{
    int k;
    cin >> n >> k;
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    cout << f(0, k, 0) << "\n";
    return 0;
}
