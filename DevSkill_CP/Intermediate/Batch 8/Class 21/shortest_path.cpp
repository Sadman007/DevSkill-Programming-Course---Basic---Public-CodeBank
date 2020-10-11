#include <bits/stdc++.h>
using namespace std;

vector<int>gr[100010];
bool vis[100010];
int color[100010];

void dfs(int u, int clr)
{
    vis[u] = 1;
    color[u] = clr;
    for(int v : gr[u]) /// u --> v
    {
        if(!vis[v])
        {
            dfs(v, clr);
        }
    }
}

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    int clr = 1;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(i, clr);
            clr++;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << i << " : " << color[i] << "\n";
    }
    return 0;
}

/**
10 9

1 2
2 4
2 5
2 6
1 3
3 7
7 9
7 10
3 8



**/
