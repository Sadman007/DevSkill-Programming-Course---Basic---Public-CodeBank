#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int n, m;
vector<int>gr[100], cost[100];
int dist[100];

void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii> >PQ;
    for(int i = 1; i <= n; i++)
        dist[i] = INT_MAX / 2;

    dist[src] = 0;
    PQ.push({0, src});

    while(!PQ.empty())
    {
        pii pu = PQ.top();
        PQ.pop();
        int u = pu.second;
        for(int i = 0; i < gr[u].size(); i++)
        {
            int v = gr[u][i];
            if(dist[v] > dist[u] + cost[u][i])
            {
                dist[v] = dist[u] + cost[u][i];
                PQ.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int  u, v, c;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        gr[u].push_back(v);
        gr[v].push_back(u);
        cost[u].push_back(c);
        cost[v].push_back(c);
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++)
        cout << i << " : " << dist[i] << "\n";
    return 0;
}

/**
7 11
1 2 5
1 5 7
2 5 9
2 3 15
2 6 6
3 5 7
3 6 8
4 5 8
4 3 5
3 7 9
6 7 11
**/
