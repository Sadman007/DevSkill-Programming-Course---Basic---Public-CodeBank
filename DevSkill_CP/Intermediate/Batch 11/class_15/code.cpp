#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

int pr[MAX + 5];
int cnt;

int find_parent(int u) /// 5 -> 4 -> 3 -> 2 -> [1]
{
    cnt++;
    if (u == pr[u]) return u;
    return pr[u] = find_parent(pr[u]);
}

void update(int u, int v)
{
    int pu = find_parent(u);
    int pv = find_parent(v);
    pr[pu] = pv;
}

int query(int u, int v)
{
    int pu = find_parent(u);
    int pv = find_parent(v);
    return pu == pv;
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        pr[i] = i;
    while(q--)
    {
        int type, u, v;
        cin >> type >> u >> v; // type : 0 -> update, 1 -> query.
        if (type == 0)
        {
            update(u, v);
        }
        else if (type == 1)
        {
            cout << query(u, v) << "\n";
        }
        cout << "COUNT: " << cnt << "\n";
    }
    return 0;
}
