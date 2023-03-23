#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
vector<int> gr[N + 5];
vector<bool> visited;

void print_graph(int n)
{
	for (int u = 1; u <= n; u++)
	{
		cout << u << " : ";
		for (auto v : gr[u])
		{
			cout << v << " ";
		}
		cout << "\n";
	}
}


void dfs(int u)
{
    cout << "entering " << u << "\n";
    getchar();
    visited[u] = true;
    for (auto v : gr[u])
    {
        if (visited[v] == false)
        {
            dfs(v);
        }
    }
    cout << "exiting " << u << "\n";
    getchar();
    /**
    for (int i = 0; i < gr[u].size(); i++)
    {
        auto v = gr[u][i];
    }
    **/
}

int main()
{
	int n, m;
	cin >> n >> m;
	visited.resize(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	dfs(1);
	return 0;
}
