#include <bits/stdc++.h>
using namespace std;
vector<int>edge_list[100];
vector<int>cost_list[100];

int main()
{
    int n, e, u, v, c;
    cin >> n >> e;
    for(int i = 0; i < e; i++)
    {
        cin >> u >> v >> c;
        edge_list[u].push_back(v);
        edge_list[v].push_back(u); /// case: undirected

        cost_list[u].push_back(c);
        cost_list[v].push_back(c);

    }
    /// print all edge_list
    for(int u = 1; u <= n; u++)
    {
        cout << u << " : ";
        for(auto v : edge_list[u])
        {
            cout << v << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    /// print all cost_list
    for(int u = 1; u <= n; u++)
    {
        cout << u << " : ";
        for(auto v : cost_list[u])
        {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
/**
4 3

1 2
1 3
3 4
**/
