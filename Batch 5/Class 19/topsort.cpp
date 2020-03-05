#include <bits/stdc++.h>
using namespace std;
#define MAX 1000006
#define ll long long
#define MOD 1000000007
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define NL puts("")

vector<int>gr[1000];
int n,m;
bool vis[1000];
stack<int>stk;

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : gr[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
    stk.push(u);
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        gr[a].push_back(b);
    }
    dfs(1);
    while(!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    puts("");
    return 0;
}
/**
1 6 7
1 3 6 7
1 2 7
1 2 5 7
**/
/**
6 7

1 3
1 2
3 5
3 6
2 4
5 4
4 6
**/
