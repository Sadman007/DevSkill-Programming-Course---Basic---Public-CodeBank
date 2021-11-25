#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 500000

int m, par[MAX + 5], sz[MAX + 5];

int find_parent(int u)
{
    if (u == par[u]) return u;
    return par[u] = find_parent(par[u]);
}

void unite(int u, int v)
{
    u = find_parent(u);
    v = find_parent(v);
    if (u != v)
    {
        if (sz[u] + sz[v] > m) return;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
    while(q--)
    {
        char ch;
        int u, v;
        cin >> ch;
        if (ch == 'S')
        {
            cin >> u;
            u = find_parent(find_parent(u));
            cout << sz[u] << "\n";
        }
        else
        {
            cin >> u >> v;
            if (ch == 'A')
            {
                unite(u, v);
            }
            else
            {
                u = find_parent(find_parent(u));
                v = find_parent(find_parent(v));
                if (u == v) cout << "Yes\n";
                else cout << "No\n";
            }
        }
    }
    return 0;
}
