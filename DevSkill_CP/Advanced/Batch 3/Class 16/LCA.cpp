#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

int P[MAX + 5][20];
int N, lgN, lvl[MAX + 5];
vector<int>gr[MAX + 5];

void dfs(int u, int pr = -1)
{
    if(pr == -1) lvl[u] = 0;
    else lvl[u] = lvl[pr] + 1;

    P[u][0] = pr;

    for(auto v : gr[u])
    {
        if(v != pr)
        {
            dfs(v, u);
        }
    }
}

void preprocess()
{
    memset(P, -1, sizeof(P));
    dfs(1);
    lgN = log2(N);
    for(int j = 1; j <= lgN; j++)
    {
        for(int i = 1; i <= N; i++)
        {
            if(P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
        }
    }
}

int getLCA(int u, int v)
{
    /// at different level?
    if(lvl[u] < lvl[v])
        swap(u, v);
    for(int i = lgN; i >= 0; i--)
    {
        if(lvl[u] - (1 << i) >= lvl[v])
            u = P[u][i];
    }
    if(u == v)
        return u;
    for(int i = lgN; i >= 0; i--)
    {
        if(P[u][i] != -1 && P[u][i] != P[v][i])
        {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}

int main()
{
    int q;
    cin >> N >> q;
    for(int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    preprocess();
    while(q--)
    {
        int u, v;
        cin >> u >> v;
        cout << getLCA(u, v) << "\n";
    }
    return 0;
}
/**
13 5
1 2
1 3
2 4
2 5
4 8
5 9
9 11
11 12
11 13
3 6
3 7
6 10


**/
