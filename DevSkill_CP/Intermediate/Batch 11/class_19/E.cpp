#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 500000

int par[MAX + 5], sz[MAX + 5];
set<pair<int, int>> component_size_by_parent;

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
        component_size_by_parent.erase({sz[u], u});
        component_size_by_parent.erase({sz[v], v});

        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        component_size_by_parent.insert({sz[u], u});
        par[v] = u;
    }
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        component_size_by_parent.insert({1, i});
        sz[i] = 1;
    }
    while (q--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        unite(u, v);
        printf("%d\n", (component_size_by_parent.rbegin()->first) - (component_size_by_parent.begin()->first));
    }
    return 0;
}
