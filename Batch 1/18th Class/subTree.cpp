#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int>adjacencyList[MAX];
int a,b,n,root;
int subTree[MAX];
bool vis[MAX];

void dfs(int u)
{
    vis[u] = 1;
    subTree[u] = 1;
    for(auto v : adjacencyList[u])
    {
        if(!vis[v])
        {
            dfs(v);
            subTree[u]+=subTree[v];
        }
    }
}

int main()
{
    cin >> n >> root;
    for(int i=0; i<n-1; i++)
    {
        cin >> a >> b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    dfs(root);
    for(int i=1; i<=n; i++) /// considering all the node labels are in between 1 to n.
    {
        printf("Node %d : SubTree size %d\n",i,subTree[i]);
    }
    return 0;
}
/**
Input for the graph we discussed in the class
16 1
1 2
1 3
1 4
2 5
2 6
3 7
3 8
3 9
4 10
4 11
4 12
7 13
10 14
11 15
11 16
**/
