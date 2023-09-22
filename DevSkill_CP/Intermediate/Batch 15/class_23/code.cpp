#include <bits/stdc++.h>
using namespace std;
#define left st, (st+en)/2, nd+nd
#define right (st+en)/2 + 1, en, nd+nd+1

const int MAX = 200005;
int nval[MAX + 5];
bool vis[MAX + 5];
vector<int> gr[MAX + 5];
int st_time[MAX + 5], en_time[MAX + 5];
long long tree[4 * MAX], arr[2 * MAX];

void dfs(int u, int &time)
{
    ++time;
    st_time[u] = time;
    vis[u] = 1;
    for (auto v : gr[u])
    {
        if (!vis[v])
        {
            dfs(v, time);
        }
    }
    en_time[u] = time;
}

void build(int st, int en, int nd)
{
    if (st == en)
    {
        tree[nd] = arr[st];
        return;
    }
    build(left);
    build(right);
    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

void update(int st, int en, int nd, int ind, int x)
{
    if (ind < st || en < ind) return;
    if (st == en && st == ind)
    {
        tree[nd] = x;
        return;
    }
    update(left, ind, x);
    update(right, ind, x);
    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

long long getsum(int st, int en, int nd, int l, int r)
{
    if (r < st || en < l) return 0;
    if (l <= st && en <= r) return tree[nd];
    return getsum(left, l, r) + getsum(right, l, r);
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &nval[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    int time = 0;
    dfs(1, time);
    for (int i = 1; i <= n; i++)
    {
        arr[st_time[i]] = nval[i];
    }
    build(1, time, 1);
    while(q--)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int s, x;
            scanf("%d %d", &s, &x);
            update(1, time, 1, st_time[s], x);
        }
        else
        {
            int s;
            scanf("%d", &s);
            printf("%lld\n", getsum(1, time, 1, st_time[s], en_time[s]));
        }
    }
    return 0;
}
