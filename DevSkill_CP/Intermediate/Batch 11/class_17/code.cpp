#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
vector<vector<int>> adjList;
bool vis[MAX + 5];

void test_adj_matrix_representation()
{
    vector<vector<int>> adj_matrix;
    int n, m;
    cin >> n >> m;
    adj_matrix.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) adj_matrix[i][i] = 1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    for (auto row : adj_matrix)
    {
        for (auto x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}


void dfs(int u)
{
    vis[u] = 1;
    cout << "current node: " << u << "\n";
    getchar();
    for (auto v : adjList[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

void test_adj_list_representation()
{
    int n, m;
    cin >> n >> m;
    adjList.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (auto x : adjList[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main()
{
    test_adj_list_representation();
    dfs(0);
    return 0;
}
