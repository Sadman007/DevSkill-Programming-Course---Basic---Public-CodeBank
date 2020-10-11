#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

struct node
{
    int v,cost;
    node(){}
    node(int _v,int _c)
    {
        v = _v;
        cost = _c;
    }
    bool operator>(const node& a)const
    {
        return cost>a.cost;
    }
};

priority_queue< node , vector<node> , greater<node> > pq;

vector<int>gr[100],cost[100];
int dist[100];

void init()
{
    for(int i=0;i<100;i++) dist[i] = INF;
    for(int i=0;i<100;i++) gr[i].clear();
    for(int i=0;i<100;i++) cost[i].clear();
}

void Dijkstra(int src)
{
    pq.push(node(src,0));
    dist[src] = 0;

    while(!pq.empty())
    {
        node n1 = pq.top();
        pq.pop();
        int u = n1.v;

        for(int i=0;i<(int)gr[u].size();i++)
        {
            int v = gr[u][i];
            if((dist[u] + cost[u][i]) < dist[v])
            {
                dist[v] = dist[u]+cost[u][i];
                pq.push(node(v,dist[v]));
            }
        }
    }
}

int main()
{
    init();
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        gr[a].push_back(b);
        gr[b].push_back(a);

        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    Dijkstra(1);
    for(int i=1;i<=n;i++)
    {
        printf("%d : %d\n",i,dist[i]);
    }
    return 0;
}


/**
4 5
1 2 10
1 3 1
2 3 1
2 4 2
3 4 5
**/
