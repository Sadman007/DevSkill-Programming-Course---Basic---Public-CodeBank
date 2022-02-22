#include <bits/stdc++.h>
using namespace std;
vector<int> adjacent_nodes[1000];
// vector<vector<int>> adjacent_nodes;
vector<int> tvalue, subtree_sum;
vector<bool> visited;

void dfs(int current_node)
{
    visited[current_node] = 1;
    subtree_sum[current_node] = tvalue[current_node];
    // cout << "current node: " << u << "\n";
    // getchar();
    for (auto neighbor : adjacent_nodes[current_node])
    {
        if (visited[neighbor] == 0)
        {
            dfs(neighbor);
            subtree_sum[current_node] += subtree_sum[neighbor];
        }
    }
    // cout << "completed traversing: " << u << "\n";
}

int main()
{
    int nodes, edges, u, v;
    cin >> nodes >> edges;

    tvalue.resize(nodes + 1, 0);
    visited.resize(nodes + 1, 0);
    subtree_sum.resize(nodes + 1, 0);

    for (int i = 1; i <= nodes; i++)
    {
        cin >> tvalue[i];
    }
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adjacent_nodes[u].push_back(v);
        adjacent_nodes[v].push_back(u); /// if directed, comment out this line
    }
    // getchar();
    dfs(1);
    cout << "subtree sum: " << subtree_sum[6] <<"\n";
    return 0;
}
/**
6 5
-5 2 20 11 17 100
1 2
1 3
1 4
3 5
3 6
**/
