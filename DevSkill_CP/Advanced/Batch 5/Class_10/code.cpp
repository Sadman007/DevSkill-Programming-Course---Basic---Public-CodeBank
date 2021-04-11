#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
vector<int>gr[MAX + 5];
vector<int> low, dis, vis;
int tim;

void dfs(int u, int pr = -1)
{
    vis[u] = 1;
    dis[u] = low[u] = tim++;
    int children = 0;
    for(auto v : gr[u])
    {
        if(v == pr) continue;
        if(vis[v]) /// already visited child / back-edge
        {
            low[u] = min(low[u], dis[v]);
        }
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dis[u] && pr != -1)
                cout << u << " is an art point!\n";
            children++;
        }
    }
    if(pr == -1 && children > 1)
        cout << u << " is an art point!\n";
}

void generateArtPoint(int n, int root)
{
    low.resize(n + 1, -1);
    dis.resize(n + 1, -1);
    vis.resize(n + 1, 0);
    tim = 1;
    dfs(root);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    generateArtPoint(n, 1);
    return 0;
}
