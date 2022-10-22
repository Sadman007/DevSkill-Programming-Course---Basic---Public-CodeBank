#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
const long long INF = LLONG_MAX / 2;
vector<pair<int, int>> gr[MAX + 5];

long long findMSTwithPrims(int n, int m, int src = 1)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    vector<long long> key(n + 1, INF);
    vector<bool> inMST(n + 1, 0);

    PQ.push({0, src});
    key[src] = 0;

    while(!PQ.empty())
    {
        auto u = PQ.top().second;
        PQ.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        for (auto it : gr[u])
        {
            int v = it.second;
            int w = it.first;
            if (inMST[v] == false && key[v] > w)
            {
                PQ.push({w, v});
                key[v] = w;
            }
        }
    }

    long long total_weight = 0;
    for (int i = 1; i <= n; i++)
    {
        total_weight += key[i];
    }
    return total_weight;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        gr[a].push_back({c, b});
        gr[b].push_back({c, a});
    }
    printf("%lld\n", findMSTwithPrims(n, m));
    return 0;
}

/**
7 11
1 2 2
1 3 3
1 4 3
2 3 4
3 4 5
2 5 3
3 5 1
3 6 6
4 6 7
5 6 8
6 7 9
**/
