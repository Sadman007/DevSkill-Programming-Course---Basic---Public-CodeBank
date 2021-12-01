#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 500000
vector<int>gr[MAX + 5];
vector<int>dist;

void bfs(int src)
{
    queue<int>Q;
    Q.push(src); /// Q = {1}
    dist[src] = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (auto v : gr[u])
        {
            if (dist[v] == INT_MAX)
            {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    dist.resize(n + 1, INT_MAX); /// dist[n]
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
        cout << i << " : " << dist[i] << "\n";
    return 0;
}

/**
7 9
1 2
2 3
3 4
3 7
1 4
2 5
2 6
6 5
5 4
**/
