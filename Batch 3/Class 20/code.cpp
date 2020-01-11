#include <bits/stdc++.h>
using namespace std;
vector<int>gr[1000],cost[1000];

struct node
{
    int u, cost;
    bool operator < (const node& a)const
    {
        return cost < a.cost;
    }
    bool operator > (const node& a)const
    {
        return cost > a.cost;
    }
};

priority_queue<node,vector<node>,greater<node> >pq;

int dist[1000],pr[1000];

void Dijkstra(int src)
{
    /// memset the dist array with inf
    for(int i=0;i<1000;i++) dist[i] = INT_MAX / 2;
    /// push the src with 0 cost in our priority queue
    dist[src] = 0;
    pq.push({src,0});
    while(!pq.empty())
    {
        node nodeU = pq.top();
        int u = nodeU.u;
        pq.pop();
        for(int i=0;i<gr[u].size();i++)
        {
            int v = gr[u][i];
            if(dist[v] > dist[u] + cost[u][i])
            {
                dist[v] = dist[u] + cost[u][i];
                pq.push({v,dist[v]});
            }
        }
    }
}

int main()
{
    int n,m,u,v,w;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        gr[u].push_back(v);
        gr[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    Dijkstra(1);
    for(int i=1;i<=n;i++) cout << i << " : " << dist[i] << endl;
    return 0;
}

/**
5 4
1 3 20
1 2 10
2 3 -1
3 4 2
**/
