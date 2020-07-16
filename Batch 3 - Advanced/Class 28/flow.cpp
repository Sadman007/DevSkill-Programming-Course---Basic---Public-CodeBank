#include <bits/stdc++.h>
using namespace std;
#define MAX 105
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define INF INT_MAX / 2

int n, m;
vector<int>gr[MAX + 5];
int capacity[MAX + 5][MAX + 5];

int bfs(int s, int t, vector<int>& parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;

        q.pop();

        for (int next : gr[cur])
        {
            if (parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t)
{
    int flow = 0;
    vector<int> parent(n + 1);
    int new_flow;

    while (1)
    {
        new_flow = bfs(s, t, parent);
        if(new_flow == 0) break;
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main()
{
    int t, u, v, w, src, dest, cs = 1;
    cin >> t;
    while(t--)
    {
    	cin >> n;
    	cin >> src >> dest >> m;
    	map<pair<int, int>, int>edges;
	    for(int i = 0; i < m; i++)
	    {
	        cin >> u >> v >> w;
	        edges[{u,v}] += w;
	        edges[{v,u}] += w;
	        gr[u].push_back(v);
	        gr[v].push_back(u);
	    }
	    for(auto it : edges)
	    {
	    	capacity[it.first.first][it.first.second] = it.second;
	    }
	    printf("Case %d: %d\n", cs++, maxflow(src, dest));
	    for(int i = 0; i <= n; i++) gr[i].clear();
	    memset(capacity, 0, sizeof(capacity));
    }
    
    
    return 0;
}
/**
6 9
1 2 7
1 3 4
3 2 3
2 4 5
2 5 3
3 5 2
5 4 3
4 6 8
5 6 5
**/
