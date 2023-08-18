#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
array<int, MAX_N> arr;
vector<int> tree[4 * MAX_N];

void build_tree(int st, int en, int node)
{
    if (st == en)
    {
        tree[node].push_back(arr[st]);
        return;
    }
    int m = st + (en - st) / 2;
    build_tree(st, m, node + node);
    build_tree(m + 1, en, node + node + 1);

    tree[node].resize(en - st + 1);
    merge(tree[2 * node].begin(), tree[2 * node].end(),
          tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
          tree[node].begin());
}

int less_or_equal_than(int st, int en, int node, int L, int R, int x)
{
    /// completely out of range!
    if (R < st || en < L) return 0;
    /// completely within range!
    if (L <= st && en <= R)
    {
        return upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();
    }
    /// partial overlap
    int m = st + (en - st) / 2;
    auto left_cnt = less_or_equal_than(st, m, node + node, L, R, x);
    auto right_cnt = less_or_equal_than(m + 1, en, node + node + 1, L, R, x);
    return left_cnt + right_cnt;
}

int solve(int L, int R, int k, int n)
{
    int lo = INT_MIN / 2;
    int hi = INT_MAX / 2;
    while(lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (less_or_equal_than(0, n - 1, 1, L, R, mid) < k)
        {
            lo = mid + 1;
        }
        else hi = mid;
    }
    return lo;
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
        int L, R, k;
        scanf("%d %d %d", &L, &R, &k);
        printf("%d\n", solve(L - 1, R - 1, k, n));
    }
    return 0;
}
