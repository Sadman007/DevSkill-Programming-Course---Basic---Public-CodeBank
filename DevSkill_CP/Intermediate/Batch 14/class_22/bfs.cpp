#include <bits/stdc++.h>
using namespace std;

vector<int> get_prime_factors_of(int u)
{
    vector<int> factors;
    int cu = u;
    for (int i = 2; i * i <= u; i++)
    {
        if (u % i == 0)
        {
            while(u % i == 0)
            {
                u /= i;
            }
            factors.push_back(i);
        }
    }
    if (u > 1 && cu != u) factors.push_back(u);
    return factors;
}

int find_path_from(int s, int t)
{
    vector<int> dist(t + 10, INT_MAX / 2);
    queue<int> Q;
    Q.push(s);
    dist[s] = 0;

    while(!Q.empty())
    {
        auto u = Q.front();
        Q.pop();
        if (u == t) break;
        auto pf = get_prime_factors_of(u);
        for (auto x : pf)
        {
            int v = u + x;
            if (v <= t && dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    return dist[t] == INT_MAX / 2 ? -1 : dist[t];
}

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        printf("Case %d: %d\n", cs++, find_path_from(s, t));
    }
    return 0;
}
