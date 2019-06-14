#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define MOD 1000000007
#define MAX 200005

/*
*****
*****
*****
*****
*****
DFS1
DFS2
*/

/*
char grid[100][100];
bool vis[100][100];

int dx[] = {-1,+1,+0,+0,+1,-1,+1,-1};
int dy[] = {+0,+0,+1,-1,+1,-1,-1,+1};

bool isV(int x,int y)
{
    return (x>=0 && y>=0 && x<n && y<m && vis[x][y]==0 && grid[x][y]=='@');
}

void dfs(int x,int y)
{
    vis[x][y] = 1;
    for(int i=0;i<8;i++)
    {
        int vx = x+dx[i];
        int vy = y+dy[i];
        if(isV(vx,vy))
        {
            dfs(vx,vy);
        }
    }
}
*/

vector<int>gr[1000];
int a,b,n,m;
bool vis[1000];
stack<int>stk;

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : gr[u])
    {
        if(!vis[v]) dfs(v);
    }
    stk.push(u); /// new line
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        gr[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    while(!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}

