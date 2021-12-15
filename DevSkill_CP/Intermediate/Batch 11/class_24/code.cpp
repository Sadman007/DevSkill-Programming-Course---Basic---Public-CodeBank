#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
#define ll long long
vector<int> gr[MAX + 5], cost[MAX + 5];

void generate_shortest_path(int src, int dst)
{
    vector<ll> dist(dst + 1, LLONG_MAX);
    vector<int> parent(dst + 1, -1);
    dist[src] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // {dist, node}
    pq.push({0, src});

    while(!pq.empty())
    {
        auto u = pq.top();
        pq.pop();
        for (int i = 0; i < gr[u.second].size(); i++)
        {
            int v = gr[u.second][i];
            int w = cost[u.second][i]; // (u.second --- v) -> w
            if (dist[v] > dist[u.second] + w)
            {
                parent[v] = u.second;
                dist[v] = dist[u.second] + w;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[dst] == LLONG_MAX)
    {
        puts("-1");
        return;
    }
    vector<int> path;

    auto find_path = [&](int u, auto&& find_path) -> void
    {
        if (u == -1) return;
        find_path(parent[u], find_path);
        path.push_back(u);
    };
    find_path(dst, find_path);

    for (int i = 0; i < path.size(); i++)
    {
        if (i) printf(" ");
        printf("%d", path[i]);
    }
    puts("");
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        gr[u].push_back(v);
        gr[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    generate_shortest_path(1, n);
    return 0;
}
