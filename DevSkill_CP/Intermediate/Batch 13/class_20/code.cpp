#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
vector<int> gr[MAX + 5];
bool vis[MAX + 5], col[MAX + 5];

void dfs(int u, int clr, bool &status)
{
    vis[u] = 1;
    col[u] = clr;
    //cout << "Visited " << u << "\n";
    //getchar();
    for (auto v : gr[u])
    {
        if (!vis[v])
        {
            dfs(v, clr ^ 1, status);
            if (!status) return;
        }
        if (col[u] == col[v])
        {
            status = false;
            return;
        }
    }
    //cout << "Completed " << u << "\n";
    //getchar();
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    bool status = true;
    dfs(1, 0, status);
    if (status) cout << "BICOLORABLE\n";
    else cout << "NOT BICOLORABLE\n";
    return 0;
}
