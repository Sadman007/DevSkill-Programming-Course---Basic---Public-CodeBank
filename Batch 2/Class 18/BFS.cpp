#include <bits/stdc++.h>
using namespace std;

vector<int>graph[100000];
int dist[100000];
bool vis[100000];

void bfs(int src){

    queue<int>Q;
    memset(vis,0,sizeof vis);
    Q.push(src);
    vis[src] = 1;
    dist[src] = 0;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(vis[v] == 1) continue;
            vis[v] = 1;
            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }
}

int main()
{
    int V,E;
    cin >> V >> E;
    for(int i=0;i<E;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(0);

    for(int i=0;i<V;i++) cout << i << " : " << dist[i] << endl;

    return 0;
}
