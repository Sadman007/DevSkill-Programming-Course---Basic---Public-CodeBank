#include <bits/stdc++.h>
using namespace std;

int dist[100000];

int getMinMove(int src,int dst) /// O(N) , N = B
{
    queue<int>Q; /// initializing a queue!
    Q.push(src); /// Q <- src

    /// dist[] infinity diye memset korlam
    for(int i=1;i<100000;i++) dist[i] = INT_MAX;

    dist[src] = 0;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int v1,v2;
        v1 = 2*u; /// max(v1) = 2 * dst
        v2 = u-1; /// min(v2) = 0
        if(v1 <= (2*dst))
        {
            if(dist[v1] > dist[u] + 1)
            {
                dist[v1] = dist[u] + 1;
                Q.push(v1);
            }
            if(v1 == dst) return dist[dst];
        }
        if(v2 >= 0)
        {
            if(dist[v2] > dist[u] + 1)
            {
                dist[v2] = dist[u] + 1;
                Q.push(v2);
            }
            if(v2 == dst) return dist[dst];
        }
    }
    return dist[dst];
}

int main()
{
    int a,b;
    cin >> a >> b;
    int minMove = getMinMove(a,b);
    cout << minMove << endl;
    return 0;
}
