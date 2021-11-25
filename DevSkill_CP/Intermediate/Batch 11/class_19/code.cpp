#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 200000

int par[MAX + 5], deg[MAX + 5];
unordered_set<int> unique_parents;

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
        par[u] = v;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        deg[u]++;
        deg[v]++;
        unite(u, v);
    }

    for (int i = 1; i <= n; i++)
    {
        unique_parents.insert(find_parent(i));
    }

    for (int i = 1; i <= n; i++)
    {
        if (deg[i] != 2)
        {
            unique_parents.erase(find_parent(i));
        }
    }

    printf("%d\n", unique_parents.size());

    return 0;
}
