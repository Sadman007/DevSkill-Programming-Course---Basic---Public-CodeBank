#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

vector<int>gr[1000];
int n,m,src,dest;
bool vis[1000];

vector<int>path;

void dfs(int u)
{
    path.push_back(u);
    vis[u] = 1;

    if(u == dest)
    {
        for(auto it : path)
        {
            cout << it << " ";
        }
        puts("");
        return;
    }

    for(auto v : gr[u])
    {
        if(!vis[v])
        {
            dfs(v);
            vis[v] = 0;
            path.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m;
    src = 1;
    dest = n;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1);
    return 0;
}
/**
1 6 7
1 3 6 7
1 2 7
1 2 5 7
**/
/**
7 9

1 2
1 3
1 6
2 4
2 5
5 7
2 7
3 6
6 7
**/
