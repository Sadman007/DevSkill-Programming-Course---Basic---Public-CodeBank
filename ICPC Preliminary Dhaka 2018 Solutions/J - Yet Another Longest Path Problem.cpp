/**
    Tag: Greedy / BFS / DFS
**/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

vector<int>gr[MAX+5];
bool vis[MAX+5];

void dfs(int u,int height)
{
    vis[u] = 1;
    for(int v : gr[u])
    {
        if(!vis[v]){
            dfs(v,1^height);
            if(height == 0) printf("%d %d\n",u,v);
            else printf("%d %d\n",v,u);
        }
    }
}

int main()
{
    int t,N,u,v,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        for(int i=0;i<N-1;i++)
        {
            scanf("%d%d",&u,&v);
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        printf("Case %d:\n",cs++);
        dfs(1,0);
        for(int i=0;i<=N;i++)
        {
            gr[i].clear();
            vis[i] = 0;
        }
    }
    return 0;
}
