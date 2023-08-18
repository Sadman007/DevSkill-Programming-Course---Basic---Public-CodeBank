#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
array<int, MAX_N> arr;
long long tree[4 * MAX_N];

void build_tree(int st, int en, int node)
{
    if (st == en)
    {
        tree[node] = arr[st];
        return;
    }
    int m = st + (en - st) / 2;
    build_tree(st, m, node + node);
    build_tree(m + 1, en, node + node + 1);
    tree[node] = tree[2 * node] + tree[(2 * node) + 1];
}

long long get_range_sum(int st, int en, int node, int L, int R)
{
    /// completely out of range!
    if (R < st || en < L) return 0;
    /// completely within range!
    if (L <= st && en <= R)
    {
        return tree[node];
    }
    /// partial overlap
    int m = st + (en - st) / 2;
    auto left_cnt = get_range_sum(st, m, node + node, L, R);
    auto right_cnt = get_range_sum(m + 1, en, node + node + 1, L, R);
    return left_cnt + right_cnt;
}

void update(int st, int en, int node, int idx, int val)
{
    /// completely out of range!
    if (idx < st || en < idx) return;
    /// completely within range!
    if (st == en && st == idx)
    {
        tree[node] = val;
        return;
    }
    int m = st + (en - st) / 2;
    update(st, m, node + node, idx, val);
    update(m + 1, en, node + node + 1, idx, val);
    tree[node] = tree[2 * node] + tree[(2 * node) + 1];
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    build_tree(0, n - 1, 1);
    while(q--)
    {
        int type, l, r;
        scanf("%d %d %d", &type, &l, &r);
        if (type == 2)
        {
            printf("%lld\n", get_range_sum(0, n - 1, 1, l - 1, r - 1));
        }
        else
        {
            update(0, n - 1, 1, l - 1, r);
        }
    }
    return 0;
}

/**
8 10
7 1 -5 6 4 10 0 3
1 3 20
0 1 3
**/

