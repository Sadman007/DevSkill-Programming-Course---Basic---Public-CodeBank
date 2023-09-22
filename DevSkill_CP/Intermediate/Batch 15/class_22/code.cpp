#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

vector<int> gr[MAX + 5], cost[MAX + 5];

vector<long long> run_dijkstra(int src, int n)
{
    vector<long long> dist(n + 1, LLONG_MAX / 2);
    vector<bool> explored(n + 1, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    PQ.push({0, src});
    dist[src] = 0;

    while(!PQ.empty())
    {
        auto [u_cost, u_node] = PQ.top();
        PQ.pop();
        if (explored[u_node]) continue;
        explored[u_node] = 1;

        for (int i = 0; i < gr[u_node].size(); i++)
        {
            int v_node = gr[u_node][i];
            auto v_cost = cost[u_node][i];
            if (dist[v_node] > dist[u_node] + v_cost)
            {
                dist[v_node] = dist[u_node] + v_cost;
                PQ.push({dist[v_node], v_node});
            }
        }
    }
    return dist;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        gr[u].push_back(v);
        cost[u].push_back(c);
    }
    auto dist = run_dijkstra(1, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld", dist[i]);
        if (i < n) printf(" ");
    }
    puts("");
    return 0;
}
