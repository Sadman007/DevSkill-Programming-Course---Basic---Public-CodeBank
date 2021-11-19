#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

vector<int>adj_list[MAX + 5];
int subtree_sum[MAX + 5];
bool vis[MAX + 5], vis2D[500][500];
int dr[] = {-1,+1,0,0};
int dc[] = {0,0,-1,+1};
/**
void dfs(int u)
{
    vis[u] = 1;
    subtree_sum[u] = u;
    cout << "Entering " << u << "\n";
    getchar();
    for (auto v : adj_list[u])
    {
        if (!vis[v])
        {
            dfs(v);
            cout << "Updating sum of " << u << " with " << v << " : " << subtree_sum[v] << "\n";
            subtree_sum[u] += subtree_sum[v];
            cout << "Current sum: " << subtree_sum[u] << "\n";
            getchar();
        }
    }
}
**/

void dfs(int r, int c)
{
    if(!is_valid(r, c)) return;
    vis2D[r][c] = 1;
    for (int i = 0; i < 4; i++)
    {
        dfs(r + dr[i], c + dc[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << subtree_sum[i] << "\n";
    }
    return 0;
}

/**
13
1 3
1 4
1 20
3 5
4 0
4 15
4 6
5 10
5 2
5 7
15 11
15 21
**/
