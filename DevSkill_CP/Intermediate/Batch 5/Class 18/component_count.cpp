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
    int component = 0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            component++;
        }
    }
    cout << component << endl;
    return 0;
}
/**
12 11

1 2
1 3
2 3
4 5
5 6
6 7
6 8
12 10
10 9
9 11
10 11
**/
