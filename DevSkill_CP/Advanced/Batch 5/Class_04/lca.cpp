#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define LEVEL 18
vector<int> tree[MAXN];
int depth[MAXN];
int parent[MAXN][LEVEL];

void init(int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < LEVEL; j++)
            parent[i][j] = -1;
    for(int i = 0; i < n; i++)
        tree[i].clear();
}

void dfs(int u, int pr)
{
    if(pr >= 0) depth[u] = depth[pr] + 1;
    parent[u][0] = pr;
    for(auto v : tree[u])
        if(v != pr) dfs(v, u);
}

void calculateTable(int n)
{
    for(int l = 1; l < LEVEL; l++)
    {
        for(int u = 0; u < n; u++)
        {
            if(parent[u][l - 1] != -1)
                parent[u][l] = parent[parent[u][l - 1]][l - 1];
        }
    }
}

int getLCA(int u, int v)
{
    if(depth[v] < depth[u]) swap(u, v);
    // made sure depth[v] >= depth[u] :)
    int diff = depth[v] - depth[u];

    for(int i = 0; i < LEVEL; i++)
    {
        if((diff & (1 << i)))
            v = parent[v][i];
    }
    if(u == v) return v;
    for(int i = LEVEL - 1; i >= 0; i--)
    {
        if(parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main()
{
    int n, u, v;
    cin >> n;
    init(n);
    for(int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0, -1);
    calculateTable(n);
    int q;
    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        cout << getLCA(u, v) << "\n";
    }
    return 0;
}

/**
15
0 1
1 2
1 3
3 4
3 5
4 6
4 7
5 8
5 9
0 10
10 11
10 12
12 13
11 14
10

**/
