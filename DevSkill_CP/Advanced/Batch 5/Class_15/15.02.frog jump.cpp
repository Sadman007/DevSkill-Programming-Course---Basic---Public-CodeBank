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

int n, D, X[LIM], big[LIM], m, N, src,dst, gcap[LIM][LIM];
int vis[LIM], send[LIM], par[LIM];

void printgraph() {
    for(int u=0; u<N; u++) {
        for(int v=0; v<N; v++) {
            if(gcap[u][v] == INF) printf("INF ");
            else printf("%3d ", gcap[u][v]);
        }
        cout << endl;
    }
    getchar();
    getchar();
}

int bfs(int src, int dst) {
//    cout << "BFS" << endl;
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
//        cout << "out " << u << endl; getchar();
        if(u == dst) break;
        for(int v=1; v<N; v++) {
            if(gcap[u][v] && !vis[v]) {
                send[v] = min(send[u], gcap[u][v]);
                par[v] = u;
                vis[v] = 1;
                q.push(v);
//                cout << "in " << v << endl; getchar();
            }
        }
    }
//    cout << "cur: " << send[dst] << endl; getchar();
    if(!vis[dst]) return 0;
    int cur = send[dst];
    int v = dst, u = par[dst];

    while(v) {
        gcap[u][v] -= cur;
        gcap[v][u] += cur;
        u = par[u];
        v = par[v];
    }

//    cout << "after graph: " << endl;
//    printgraph();

    return cur;
}

int flow(int src, int dst) {
    int ans = 0;
    while(true) {

//        printgraph();

        int cur = bfs(src, dst);
        if(!cur) break;
        ans += cur;
//        cout << "Flow " << ans << endl;
    }
    return ans;
}

int solve(int x, int src, int dst) {
    memset(gcap, 0, sizeof gcap);

    ///node cap
    for(int u=1; u<=n; u++) {
        if(big[u]) {
            gcap[u][u+n] = INF;
        }
        else {
            gcap[u][u+n] = 1;
        }
    }

    ///connect with source
    for(int u=1; u<=n; u++) {
        if(X[u] <= x) {
            gcap[src][u] = INF;
        }
    }
    if(D <= x) gcap[src][dst] = INF;

    /// internal nodes
    for(int u=1; u<=n; u++) {
        for(int v=u+1; v<=n; v++) {
            if(abs(X[u]-X[v]) <= x) {
                gcap[u+n][v] = INF;
                gcap[v+n][u] = INF;
            }
        }
    }

    ///connect with destination
    for(int u=1; u<=n; u++) {
        if(D-X[u] <= x) {
            gcap[u+n][dst] = INF;
        }
    }

//    cout << "TRY " << x << endl;

    return flow(src, dst);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &D);
        for(int u=1; u<=n; u++) {
            getchar();
            char tp;
            scanf("%c-%d", &tp, &X[u]);
            if(tp == 'B') {
                big[u] = 1;
            }
            else {
                big[u] = 0;
            }
        }

        src = 0, dst = 2*n+1; N = 2*n+2;

        int lo = 0, hi = INF;
        while(lo < hi) {
            int x = (lo+hi)/2;
            if(solve(x, src, dst) >= 2) hi = x;
            else lo = x+1;
        }

        printf("Case %d: %d\n", t, hi);
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
