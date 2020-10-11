#include <bits/stdc++.h>
using namespace std;
vector<int>gr[1000];
bool vis[1000];

void dfs(int u)
{
    vis[u] = 1;
    for(int v : gr[u])
    {
        if(vis[v] == 0)
        {
            dfs(v);
        }
    }
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1);
    return 0;
}
