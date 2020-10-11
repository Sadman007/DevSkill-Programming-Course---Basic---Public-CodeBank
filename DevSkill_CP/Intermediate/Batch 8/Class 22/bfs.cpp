#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define INF 1000000000

int n, m, dist[MAX + 5];
vector<int>gr[MAX + 5];

void bfs(int src)
{
    ///init
    queue<int>Q;
    Q.push(src);
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[src] = 0;

    ///simulate
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(auto v : gr[u])
        {
            if(dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int u, v, src;
    cin >> n >> m >> src;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    bfs(src);
    for(int i = 1; i <= n; i++)
    {
        cout << i << " : " << dist[i] << "\n";
    }
    return 0;
}


/**
9 12 3

1 2
1 7
1 4
1 6
2 7
7 8
8 9
2 3
3 4
2 5
4 6
3 5

**/
