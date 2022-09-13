#include <bits/stdc++.h>
using namespace std;
#define left st, (st + en)/2, nd + nd
#define right (st+en)/2 + 1, en, nd + nd + 1

const int MAX = 100010;
int tree[4 * MAX], arr[MAX];

void buildTree(int st, int en, int nd) /// [0, 7]
{
    if (st == en)
    {
        tree[nd] = arr[st];
        return;
    }
    buildTree(left);
    buildTree(right);
    tree[nd] = min(tree[nd + nd], tree[nd + nd + 1]);
}

int getMin(int st, int en, int nd, int L, int R)
{
    if (en < L || R < st) return INT_MAX / 2;
    if (L <= st && en <= R) return tree[nd];
    return min(getMin(left, L, R), getMin(right, L, R));
}

void pointUpdate(int st, int en, int nd, int idx, int v)
{
    if (en < idx || idx < st) return;
    if (st == en)
    {
        tree[nd] = v;
        return;
    }
    pointUpdate(left, idx, v);
    pointUpdate(right, idx, v);
    tree[nd] = min(tree[nd + nd], tree[nd + nd + 1]);
}

int main()
{
    int T, cs = 1, n, L, R, q, type;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < 4 * n; i++) tree[i] = INT_MAX / 2;

        buildTree(0, n - 1, 1);
        printf("Case %d:\n", cs++);
        while(q--)
        {
            // scanf("%d", &type);
            type = 1;
            if (type == 1) // range min
            {
                scanf("%d %d", &L, &R);
                --L, --R;
                printf("%d\n", getMin(0, n - 1, 1, L, R));
            }
            else if (type == 0)
            {
                int idx, v;
                scanf("%d %d", &idx, &v);
                --idx;
                pointUpdate(0, n - 1, 1, idx, v); /// arr[idx] = v
            }
        }
    }
    return 0;
}
