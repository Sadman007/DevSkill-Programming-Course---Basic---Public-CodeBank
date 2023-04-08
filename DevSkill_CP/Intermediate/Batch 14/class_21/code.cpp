#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
vector<int> gr[MAX + 5];
vector<int> mark;

void dfs(int u, int dfs_cnt)
{
    mark[u] = dfs_cnt;
    for (auto v : gr[u])
    {
        if (mark[v] == -1)
        {
            dfs(v, dfs_cnt);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    mark.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    int dfs_cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == -1)
        {
            dfs(i, dfs_cnt);
            dfs_cnt++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << mark[i] << "\n";
    }
    cout << dfs_cnt << "\n";
    return 0;
}
