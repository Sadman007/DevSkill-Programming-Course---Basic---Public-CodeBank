#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000
#define MAX 500000
#define ll long long

struct node
{
    ll v,cost;
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

vector<int>gr[MAX+10],cost[MAX+10];
ll dist[MAX+10];
int par[MAX+10];

void init()
{
    for(int i=0;i<MAX;i++) dist[i] = INF;
    for(int i=0;i<MAX;i++) gr[i].clear();
    for(int i=0;i<MAX;i++) cost[i].clear();
    for(int i=0;i<MAX;i++) par[i] = -1;
}

void Dijkstra(int src)
{
    pq.push(node(src,0));
    pq.push(node(src2,0));
    dist[src] = 0;
    dist[src2] = 0;

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
                par[v] = u;
                dist[v] = dist[u]+cost[u][i];
                pq.push(node(v,dist[v]));
            }
        }
    }
}

void printPath(int u)
{
    if(u==-1) return;
    printPath(par[u]);
    printf("%d ",u);
}

int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        gr[a].push_back(b);
        gr[b].push_back(a);

        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    Dijkstra(1);
    if(dist[n]==INF) puts("-1");
    else printPath(n);
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
