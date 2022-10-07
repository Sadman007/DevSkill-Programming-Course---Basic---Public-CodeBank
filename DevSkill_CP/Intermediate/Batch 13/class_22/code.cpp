#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
int pr[MAX + 5], sz[MAX + 5];
string s;

int findParent(int x)
{
    if (x == pr[x]) return x;
    return pr[x] = findParent(pr[x]);
}

void join(int x, int y)
{
    int px = findParent(x);
    int py = findParent(y);
    sz[px] += sz[py];
    pr[py] = px;
}

int getSize(int x)
{
    return sz[findParent(x)];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n >> s;
        vector<int> from(26, -1), to(26, -1);
        string res = "";
        for (int i = 0; i < 30; i++)
        {
            pr[i] = i;
            sz[i] = 1;
        }
        for (auto ch : s)
        {
            int x = ch - 'a';
            if (from[x] != -1)
            {
                res += 'a' + from[x];
                continue;
            }
            for (int y = 0; y < 26; y++)
            {
                if (to[y] != -1) continue; // already y pick korsi karo jonne
                if (findParent(x) == findParent(y) && getSize(x) < 26)
                {
                    continue;
                }
                from[x] = y;
                to[y] = x;
                join(x, y);
                res += 'a' + from[x];
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
