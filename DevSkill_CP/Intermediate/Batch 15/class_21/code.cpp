#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;

vector<int> gr[MAX + 5];

vector<int> bfs(int src, int n)
{
    vector<int> dist(n + 1);
    vector<bool> mark(n + 1, 0);
    queue<int> Q;

    // initialization
    Q.push(src);
    mark[src] = true;
    dist[src] = 0;

    // traversal
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (auto v : gr[u])
        {
            if (!mark[v])
            {
                mark[v] = true;
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    return dist;
}

int main()
{
    int n, m, u, v, src;
    cin >> n >> m >> src;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    auto dist = bfs(src, n);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << dist[i] << "\n";
    }
    return 0;
}
