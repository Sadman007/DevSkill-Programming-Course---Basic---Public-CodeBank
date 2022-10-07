#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int pr[MAX + 5];

/// O(4 * N) = avg O(1)
int findLeader(int u)
{
    if (u == pr[u]) return u;
    return pr[u] = findLeader(pr[u]); // u --> pr[u] /// 5 --> [4] --> 3
}

void connect(int u, int v)
{
    int lu = findLeader(u);
    int lv = findLeader(v);
    pr[lu] = lv;
}

int main()
{
    int q, n;
    cin >> n;
    for (int i = 1; i <= n; i++) pr[i] = i;
    cin >> q;
    while(q--)
    {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) // connect
        {
            connect(u, v);
        }
        else if (type == 2) // isConnected
        {
            u = findLeader(u);
            v = findLeader(v);
            if (u == v) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
