#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define left st, (st + en) / 2, nd + nd
#define right (st + en) / 2 + 1, en, nd + nd + 1

int tree[4 * MAX + 5], arr[MAX + 5];
void build(int st, int en, int nd)
{
    if (st == en)
    {
        tree[nd] = arr[st];
        return;
    }
    build(left);
    build(right);
    tree[nd] = tree[nd + nd] + tree[nd + nd + 1]; // min(tree[nd + nd), tree[nd + nd + 1)
}
int query(int st, int en, int nd, int L, int R)
{
    if (en < L || R < st) return 0;
    if (L <= st && en <= R) return tree[nd];
    return query(left, L, R) + query(right, L, R);
}
void update(int st, int en, int nd, int idx, int value)
{
    if (en < idx || idx < st) return;
    if (st == en && st == idx)
    {
        tree[nd] = value;
        return;
    }
    update(left, idx, value);
    update(right, idx, value);
    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(0, n - 1, 1);
    while(q--)
    {
        int com;
        cin >> com;
        if (com == 0)
        {
            int l, r;
            cin >> l >> r;
            cout << query(0, n - 1, 1, l, r) << "\n";
        }
        else
        {
            int idx, value;
            cin >> idx >> value;
            update(0, n - 1, 1, idx, value);
        }
    }
    return 0;
}
