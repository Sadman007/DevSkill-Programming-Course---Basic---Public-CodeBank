#include <bits/stdc++.h>
using namespace std;
string a, b;
bool vis[110][110];
string dp[110][110];

string findLCS(int p1, int p2)
{
    if (p1 >= a.size() || p2 >= b.size()) return "";
    if (vis[p1][p2]) return dp[p1][p2];

    vis[p1][p2] = 1;

    // if match found
    if (a[p1] == b[p2])
    {
        dp[p1][p2] = a[p1] + findLCS(p1 + 1, p2 + 1);
    }
    else
    {
        string t1 = findLCS(p1 + 1, p2);
        string t2 = findLCS(p1, p2 + 1);
        if (t1.size() == t2.size())
            dp[p1][p2] = min(t1, t2);
        else
            dp[p1][p2] = t1.size() > t2.size() ? t1 : t2;
    }
    return dp[p1][p2];
}

int main()
{
    // freopen("out.txt", "w", stdout);
    int t, cs = 1;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        memset(vis, 0, sizeof vis);
        string lcs = findLCS(0, 0);
        if (lcs.size() == 0) lcs = ":(";
        cout << "Case " << cs++ << ": " << lcs << "\n";
    }
    return 0;
}
