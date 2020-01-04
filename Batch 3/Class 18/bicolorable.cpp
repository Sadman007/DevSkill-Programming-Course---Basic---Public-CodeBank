#include <bits/stdc++.h>
using namespace std;
vector<int>gr[1000];
bool vis[1000];
int color[1000];

bool colorable;

void dfs(int u,int nodeClr)
{
    vis[u] = 1;
    color[u] = nodeClr;

    for(int v : gr[u])
    {
        if(vis[v] == 0)
        {
            dfs(v,nodeClr ^ 1);
        }
        if(color[v] == nodeClr)
        {
            colorable = false;
            return;
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
    colorable = true;
    dfs(1,0);
    if(colorable) puts("Bicolorable");
    else puts("Non-bicolorable");
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


