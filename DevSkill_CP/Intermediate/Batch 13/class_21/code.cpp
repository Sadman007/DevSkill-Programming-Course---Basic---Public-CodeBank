#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
vector<int> gr[MAX + 5];
vector<int> dist;

void bfs(vector<int> &srcs, int n)
{
    dist.clear();
    dist.resize(n + 1, INT_MAX / 2);
    queue<int> Q;
    for (auto src : srcs)
    {
        Q.push(src);
        dist[src] = 0;
    }
    while(!Q.empty())
    {
        auto u = Q.front();
        Q.pop();
        for (auto v : gr[u])
        {
            if (dist[v] == INT_MAX / 2)
            {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    bfs({1}, n);
    for (int i = 1; i <= n; i++)
    {
        cout << "dist: " << i << " " << dist[i] << "\n";
    }
    return 0;
}
/**
10 13
1 2

1 3

1 4

1 7

2 5

2 6

3 6

3 10

7 10

7 4

4 8

8 9

7 9

**/
