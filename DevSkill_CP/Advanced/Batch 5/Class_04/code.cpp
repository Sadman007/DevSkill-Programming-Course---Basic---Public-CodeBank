#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

vector<int>tree[MAX + 5];
int depth[MAX + 5], parent[MAX + 5][20];

void dfs(int u, int pr)
{
    if(pr != -1) depth[u] = depth[pr] + 1;
    parent[u][0] = pr;

    for(auto v : tree[u])
        if(v != pr)
            dfs(v, u);
}

void calculateTable(int n) /// O(nlogn)
{
    int lg = log2(n) + 1;
    for(int i = 1; i <= lg; i++)
    {
        for(int u = 0; u < n; u++)
        {
            if(parent[u][i - 1] != -1)
                parent[u][i] = parent[parent[u][i - 1]][i - 1];
        }
    }
}

int getLCA(int n, int u, int v)
{
    if(depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    int lg = log2(n) + 1;
    for(int i = 0; i <= lg; i++)
    {
        if(diff & (1 << i))
            v = parent[v][i];
    }
    /// depth[u] == depth[v]
    if(u == v) return u;
    for(int i = lg; i >= 0; i--)
    {
        if(parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

void init(int n)
{
    int lg = log2(n) + 1;
    for(int i = 0; i < n; i++)
    {
        tree[i].clear();
        depth[i] = 0;

        for(int j = 0; j <= lg; j++)
            parent[i][j] = -1;
    }
}

int main()
{
    int n, u, v, q;
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
    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        cout << getLCA(n, u, v) << "\n";
    }
    return 0;
}

/**
21
0 1
1 3
3 5
5 9
9 15
9 16
3 6
6 10
10 17
6 11
6 12
12 18
1 20
0 2
2 4
4 7
4 8
7 13
7 14
14 19
**/

