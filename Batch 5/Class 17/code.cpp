#include <bits/stdc++.h>
using namespace std;

vector<int>graph[1000];
int pr[1000],dist[1000];

void bfs(int src) /// O(V + E) --> O(N)
{
    queue<int>Q;
    Q.push(src);
    dist[src] = 0;
    pr[src] = -1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int v : graph[u]) /// for(int i=0;i<graph[u].size();i++) int v = graph[u][i]
        {
            if(dist[v] > dist[u] + 1)
            {
                pr[v] = u;
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}

void pathPrint(int u)
{
    while(u != -1)
    {
        cout << u;
        if(pr[u]!=-1) cout << "<-";
        u = pr[u];
    }
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1;i<=n;i++) dist[i] = INT_MAX;

    bfs(1);

    pathPrint(6);

    for(int i=1;i<=n;i++)
    {
        //cout << i << " : " << dist[i] << endl;
    }
    return 0;
}

/**
6 6

1 2
1 3
1 5
3 5
1 4
5 6
**/
