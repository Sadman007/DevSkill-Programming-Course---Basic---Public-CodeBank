#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define left st, (st + en) / 2, nd + nd
#define right (st + en) / 2 + 1, en, nd + nd + 1
int tree[4 * MAX + 5];
int n, arr[MAX + 5];

void build(int st, int en, int nd)
{
    if(st == en)
    {
        tree[nd] = arr[st];
        return;
    }
    build(left); /// left subtree
    build(right); /// right subtree
    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

int query(int st, int en, int nd, int L, int R)
{
    if(L <= st && en <= R) return tree[nd]; /// if the query segment is completely overlapping our tree segment/node.
    if(en < L || R < st) return 0;
    return query(left, L, R) + query(right, L, R);
}

void update(int st, int en, int nd, int idx, int v)
{
    if(en < idx || idx < st) return;
    if(st == en)
    {
        tree[nd] += v;
        return;
    }
    update(left, idx, v);
    update(right, idx, v);
    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

int main()
{
    /// build(0, n - 1, 1);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(0, n - 1, 1); /// O(4 * N)
    int Q;
    cin >> Q;
    while(Q--)
    {
        int com;
        cin >> com;
        if(com == 0) /// update
        {
            int idx, v;
            cin >> idx >> v;
            update(0, n - 1, 1, idx, v);
        }
        else if(com == 1) /// query
        {
            int L, R;
            cin >> L >> R;
            cout << query(0, n - 1, 1, L, R) << "\n";
        }
    }
    return 0;
}
