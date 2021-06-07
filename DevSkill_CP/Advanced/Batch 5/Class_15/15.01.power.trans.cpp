#include <bits/stdc++.h>
#define LIM 205
#define INF 1000000009

using namespace std;

/**
max flow:
number of node = n
number of edge = m
source = 1
destination = n
*/

int n, m, N, src,dst, gcap[LIM][LIM], B, D;
int vis[LIM], send[LIM], par[LIM];

int bfs(int src, int dst) {
//    cout << "BFS" << endl; getchar();
    memset(vis, 0, sizeof vis);
    memset(par, 0, sizeof par);
    memset(send, 0, sizeof send);
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    send[src] = INF;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

//        cout << "OUT" << u << endl; getchar();

        if(u == dst) break;
        for(int v=1; v<=N; v++) {
            if(gcap[u][v] && !vis[v]) {
                send[v] = min(send[u], gcap[u][v]);
                par[v] = u;
                vis[v] = 1;
                q.push(v);
//                cout << "IN " << v << endl; getchar();
            }
        }
    }
    if(!vis[dst]) return 0;
    int cur = send[dst];
    int v = dst, u = par[dst];

    while(u) {
        gcap[u][v] -= cur;
        gcap[v][u] += cur;
        u = par[u];
        v = par[v];
    }
    return cur;
}

int flow(int src, int dst) {
    int ans = 0;
    while(true) {
        int cur = bfs(src, dst);
        if(!cur) break;
        ans += cur;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        memset(gcap, 0, sizeof gcap);
        for(int u=1; u<=n; u++) {
            int c;
            scanf("%d", &c);
            gcap[u][n+u] += c;
        }
        scanf("%d", &m);
        for(int i=0; i<m; i++) {
            int u,v,c;
            scanf("%d %d %d", &u, &v, &c);
            gcap[u+n][v] += c;
        }

        src = 0;
        dst = 2*n+1;
        N = 2*n+2;

        scanf("%d %d", &B, &D);
        for(int i=0; i<B; i++) {
            int u;
            scanf("%d", &u);
            gcap[src][u] = INF;
        }
        for(int i=0; i<D; i++) {
            int u;
            scanf("%d", &u);
            gcap[u+n][dst] = INF;
        }

//        for(int u=src; u<=dst; u++) {
//            for(int v=src; v<=dst; v++) {
//                cout << gcap[u][v] << " ";
//            }
//            cout << endl;
//        }

        printf("Case %d: %d\n", t, flow(src,dst));
    }
}

/**
11
1 11 16
1 2 8
1 3 4
1 4 5
2 5 5
2 6 2
3 6 3
4 7 4
5 8 4
6 9 6
7 9 2
7 10 3
8 11 5
9 8 3
9 11 5
9 10 2
10 11 4

2
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
4
1 4 2
1 4 20
1 4 20
*/
