#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
vector<int> arr;
int tree[4 * MAXN + 5];

/// O(4 * N)
void build(int st, int en, int nd)
{
    if (st == en)
    {
        tree[nd] = arr[st];
        return;
    }
    int M = (st + en) / 2;
    build(st, M, nd + nd);
    build(M + 1, en, nd + nd + 1);
    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

int query(int st, int en, int nd, int l, int r)
{
    if (en < l || r < st)
    {
        return 0;
    }
    if (l <= st && en <= r)
    {
        return tree[nd];
    }
    int M = (st + en) / 2;
    int leftSubtree = query(st, M, nd + nd, l, r);
    int rightSubtree = query(M + 1, en, nd + nd + 1, l, r);
    return leftSubtree + rightSubtree;
}

void update(int st, int en, int nd, int x, int val)
{
    /// OUTSIDE?
    /// INSIDE
    /// left e jaben
    /// right e jaben
    /// left ar right child er value gula ke parent e update kore diben
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(0, n - 1, 1);
    int q;
    cin >> q;
    while(q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r; /// 0 - based
            cout << query(0, n - 1, 1, l, r) << "\n";
        }
        else
        {
            int x, val;
            cin >> x >> val;
            update(0, n - 1, 1, x, val);
        }
    }
    return 0;
}
