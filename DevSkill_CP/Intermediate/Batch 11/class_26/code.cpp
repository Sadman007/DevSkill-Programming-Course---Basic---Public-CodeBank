#include <bits/stdc++.h>
using namespace std;

string s, cur;
int r;
bool vis[40];

void gen(int pos) /// aa
{
    if (cur.size() == r)
    {
        cout << cur << "\n";
        return;
    }
    for (int i = pos; i < s.size(); i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            cur.push_back(s[i]);
            gen(i + 1);
            vis[i] = 0;
            cur.pop_back();
        }
        while (i + 1 < s.size() && s[i] == s[i + 1]) i++;
    }
}

int main()
{
    while(cin >> s >> r)
    {
        cur = "";
        memset(vis, 0, sizeof vis);
        sort(s.begin(), s.end());
        gen(0);
    }
    return 0;
}
