#include <bits/stdc++.h>
using namespace std;
vector<int>gr[1000];
bool vis[1000];
bool hasCycle = false;

void dfs(int u,int pr)
{
    vis[u] = 1;
    for(int v : gr[u])
    {
        if(vis[v] == 0)
        {
            dfs(v,u);
        }
        else if(vis[v] == 1 && v != pr)
        {
            hasCycle = true;
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
    hasCycle = false;
    dfs(1,-1);
    if(hasCycle) puts("Cyclic Graph");
    else puts("Non-cyclic Graph");
    return 0;
}
/**
6 7

1 2
2 3
3 1
3 4
4 5
5 6
4 6
**/

