#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MX 1010
#define INF 1000000000LL
#define pii pair<int,int>

vector<int>gr[MX+5],cst[MX+5],edge[MX+5];
int dist[MX+5];

void dijkstra(int src){
	memset(dist,0x3f3f3f3f,sizeof dist);
	priority_queue<pii>pq;
	pq.push(pii(0,src));
	dist[src]=0;
	while(!pq.empty()){
		auto u = pq.top();
		pq.pop();
		for(int i=0;i<(int)gr[u.second].size();i++){
			int v = gr[u.second][i];
			if(dist[v]>dist[u.second]+cst[u.second][i]){
				dist[v]=dist[u.second]+cst[u.second][i];
			    pq.push(pii(dist[v],v));
			}
		}
	}
}

int main(){
    ll n,m,L,s,t,u,v,w;
    cin >> n >> m;
    for(int i=0;i<m;i++){
    	cin >> u >> v >> w;
    	gr[u].pb(v);
    	gr[v].pb(u);
    	cst[u].pb(w);
    	cst[v].pb(w);
    }
    dijkstra(0);
    for(int i = 0;i<n;i++){
    	cout << i << ": " << dist[i] << endl;
    }
}
