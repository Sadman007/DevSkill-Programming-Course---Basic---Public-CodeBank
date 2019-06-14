#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 5500
#define ll long long

struct node
{
    ll v,cost;
    node() {}
    node(ll _v,ll _c)
    {
        v = _v;
        cost = _c;
    }
    bool operator>(const node& a)const
    {
        return cost>a.cost;
    }
    bool operator<(const node& a)const
    {
        return cost<a.cost;
    }
};

vector<ll>gr[MAX+10],cost[MAX+10];
ll dist[MAX+10],dist2[MAX+10];

void init()
{
    for(int i=0; i<MAX; i++)
        {dist[i] = INF;dist2[i] = INF;}
    for(int i=0; i<MAX; i++)
        gr[i].clear();
    for(int i=0; i<MAX; i++)
        cost[i].clear();
}

void DijkstraFor2ndBest(int src)
{
    priority_queue< node, vector<node>, greater<node> > pq;
    pq.push(node(src,0));
    dist[src] = 0;

    while(!pq.empty())
    {
        node n1 = pq.top();
        pq.pop();
        ll u = n1.v;

        for(int i=0;i<(int)gr[u].size();i++)
        {
            ll w = cost[u][i];
            ll v = gr[u][i];

            if(dist[v]>(w+dist[u]))
            {
                dist2[v] = dist[v];
                dist[v] = w+dist[u];
                pq.push(node(v,dist[v]));
            }

            else if((w+dist[u])>=dist[v] && (w+dist[u])<dist2[v])
            {
                if((w+dist[u])==dist[v])
                {
                    if((w+dist2[u])<dist2[v])
                        dist2[v] = w+dist2[u];
                }
                else dist2[v] = w+dist[u];
                pq.push(node(v,dist[v]));
            }

        }
    }
}

int main()
{
    int test,cs=1;
    scanf("%d",&test);
    while(test--)
    {
        init();
        ll n,m;
        scanf("%lld%lld",&n,&m);
        for(int i=0; i<m; i++)
        {
            ll a,b,c;
            scanf("%lld%lld%lld",&a,&b,&c);
            gr[a].push_back(b);
            gr[b].push_back(a);

            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        DijkstraFor2ndBest(1);
        //for(int i=1;i<=n;i++) printf("%d : %d\n",i,dist2[i]);
        printf("Case %d: %lld\n",cs++,dist2[n]);

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
