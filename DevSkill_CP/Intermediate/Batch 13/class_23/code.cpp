#include <bits/stdc++.h>
using namespace std;

const int MAX = 100010;
const long long INF = LLONG_MAX / 2;
vector<pair<long long, int>> E[MAX + 5];

vector<long long> generateShortestPath(int src, int n) /// O(VlogE)
{
    vector<long long> D(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > PQ;
    PQ.push({0, src});
    D[src] = 0;
    while(!PQ.empty())
    {
        auto p = PQ.top();
        PQ.pop();
        int u = p.second;
        long long d = p.first;
        if (d > D[u]) continue;
        for (auto pr : E[u])
        {
            int v = pr.second; // pr = (dist_v, node_v)
            long long next_d = d + pr.first;
            if (next_d < D[v])
            {
                D[v] = next_d;
                PQ.push({next_d, v});
            }
        }
    }
    return D;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        E[a].push_back({c, b}); // (dist, node)
    }
    auto D = generateShortestPath(1, n); // apply dijkstra
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", D[i]);
    }
    return 0;
}
