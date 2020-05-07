#include <bits/stdc++.h>
using namespace std;

#define MAX 100050
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

#define left st, (st + en) / 2, nd + nd
#define right ((st + en) / 2) + 1, en, nd + nd + 1

ll tree[4 * MAX + 5], lazy[4 * MAX + 5], arr[4 * MAX + 5];

void pushDown(int st, int en, int nd)
{
    if(!lazy[nd] || st == en) return;
    int mid = (st + en) / 2;
    tree[nd + nd] += (mid - st + 1)*lazy[nd];
    tree[nd + nd + 1] += (en - mid)*lazy[nd];
    lazy[nd + nd] += lazy[nd];
    lazy[nd + nd + 1] += lazy[nd];
    lazy[nd] = 0;
}

void update(int st, int en, int nd, int L, int R, int val)
{
    pushDown(st, en, nd);
    if(R < st || en < L) return;
    if(L <= st && en <= R)
    {
        tree[nd] = tree[nd] + (val*(en - st + 1));
        lazy[nd] += val;
        return;
    }
    update(left, L, R, val); /// left
    update(right, L, R, val); /// right
    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

ll query(int st, int en, int nd, int L, int R)
{
    pushDown(st, en, nd);
    if(R < st || en < L) return 0;
    if(L <= st && en <= R) return tree[nd];
    return query(left,L,R) + query(right,L,R);
}

int main()
{
    int n, T, q, L, R, val, com, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &q);
        for(int i = 0; i <= 4*n; i++) arr[i] = lazy[i] = tree[i] = 0;
        printf("Case %d:\n", cs++);
        while(q--)
        {
            scanf("%d", &com);
            if(com == 0)
            {
                scanf("%d %d %d", &L, &R, &val);
                update(0, n - 1, 1, L, R, val);
            }
            else
            {
                scanf("%d %d", &L, &R);
                printf("%lld\n", query(0, n - 1, 1 ,L ,R));
            }
        }
    }
    return 0;
}
