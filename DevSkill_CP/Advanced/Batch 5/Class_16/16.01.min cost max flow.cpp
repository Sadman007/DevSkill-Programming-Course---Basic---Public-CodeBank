#include <bits/stdc++.h>
#define LIM 55
#define pii pair<int,int>
#define INF 1009

using namespace std;

int n,m, cap[LIM][LIM], prf[LIM][LIM];

void print(int V, vector<vector<int>> &gcap, vector<vector<int>> &gprf) {
    for(int u=0; u<V; u++) {
        for(int v=0; v<V; v++) {
            printf("(%3d,%3d) ", gcap[u][v], gprf[u][v]);
//            printf("%3d ", gcap[u][v]);
        }
        cout << endl;
    }
    getchar();
}

pii dij(int V, vector<vector<int>> &gcap, vector<vector<int>> &gprf, int src, int dst) {
    vector<int> key(V, -INF);
    vector<int> par(V, -1);
    priority_queue<pii> pq;
    pq.push({0, src});
    key[src] = 0;

    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        int u = cur.second;
        int p = cur.first;

        for(int v=0; v<V; v++) {
            if(gcap[u][v]) {
                if(p+gprf[u][v] > key[v]) {
                    key[v] = p+gprf[u][v];
                    par[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
    }

    if(key[dst] == -INF) return {0, 0};

    int u = par[dst], v = dst, flow = 1, profit = 0;

    while(u != -1) {
        profit += gprf[u][v];
        gprf[v][u] = -gprf[u][v];
        gprf[u][v] = 0;

        gcap[u][v] -= flow;
        gcap[v][u] += flow;

        u = par[u];
        v = par[v];
    }

    return {flow, profit};
}

pii max_cost_max_flow(int V, vector<vector<int>> &gcap, vector<vector<int>> &gprf, int src, int dst) {
    int flow = 0, profit = 0;
    while(true) {
//        print(V, gcap, gprf);
        pii cur = dij(V, gcap, gprf, src, dst);
//        cout << "cur " << cur.first << ' ' << cur.second << endl; getchar();
        if(!cur.first) break;
        flow += cur.first;
        profit += cur.second;
    }
    return {flow, profit};
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        int src = 0, dst = 2*n+1, V = 2*n+2;
        memset(prf, 0, sizeof prf);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &prf[i][j]);
            }
        }

        vector<vector<int>> gcap(V, vector<int>(2*n+2, 0));
        vector<vector<int>> gprf(V, vector<int>(2*n+2, 0));

        for(int u=1; u<=n; u++) gcap[src][u] = 1, gprf[src][u] = 0;
        for(int v=n+1; v<=2*n; v++) gcap[v][dst] = 1, gprf[v][dst] = 0;
        for(int u=1; u<=n; u++) {
            for(int v=1; v<=n; v++) {
                gcap[u][n+v] = 1;
                gprf[u][n+v] = prf[u][v];
            }
        }

        printf("Case %d: %d\n", t, max_cost_max_flow(V, gcap, gprf, src, dst).second);
    }
}


/**
2
2
4 3
3 1
3
1 4 5
5 7 6
5 8 8
*/
