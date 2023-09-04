#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;

vector<int> adj[MAX + 5];
vector<bool> vis;

void dfs(int u)
{
    vis[u] = 1;
    score[u] = value[u];
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
            score[u] += score[v];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vis.resize(n + 1, 0);
    dist.resize(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << dist[i] << "\n";
    }

    return 0;
}
