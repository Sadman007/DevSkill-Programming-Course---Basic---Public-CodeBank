#include <bits/stdc++.h>
using namespace std;

/**
    Problems:
        1. LOJ 1141 - Number Transformation (DONE)
        2. SPOJ PT07Z - Longest path in a tree (DONE)
        3. DFS (DONE) + Flood Fill
        4. Bipartite Graph / Graph Bicoloring
**/

vector<int>graph[1000];
int V,E,u,v;
bool vis[1000];

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : graph[u])
    {
        if(!vis[v]) dfs(v);
    }
}

int main()
{
    cin >> V >> E;
    for(int i=0;i<E;i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int noOfComponent = 0;
    for(int i=1;i<=V;i++)
    {
        if(vis[i] == 0)
        {
            noOfComponent++;
            dfs(i);
        }
    }
    cout << "No of comp is " << noOfComponent << endl;
    return 0;
}

/**
7 7
1 2
1 5
2 5
2 3
2 4
6 7
2 6
**/
