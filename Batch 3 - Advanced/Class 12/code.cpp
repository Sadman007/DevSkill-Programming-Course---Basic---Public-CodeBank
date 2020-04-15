#include <bits/stdc++.h>
using namespace std;

#define MAX 100050
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()

#define left st, (st + en) / 2, nd + nd
#define right (st + en) / 2 + 1, en, nd + nd + 1

int arr[MAX + 5], brr[MAX + 5];
ll tree[4 * MAX];

void compress(int n)
{
    /**
          arr -> 5 12 7 2 100 2

          brr -> 5 12 7 2 100 2

    sort(brr) -> 2 2 5 7 12 100
        brr   -> 1 1 2 3 4 5

          arr -> 2 4 3 1 5 1
    **/
    sort(brr, brr + n);
    unordered_map<int,int>ump;
    int v = 1;
    for(int i = 0; i < n; i++)
    {
        if(ump.find(brr[i]) == ump.end())
        {
            ump[brr[i]] = v++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        arr[i] = ump[arr[i]];
    }
}

void update(int st, int en, int nd, int idx, int val)
{
    if(st > idx || en < idx) return;
    if(st == en && st == idx)
    {
        tree[nd] += val;
        ///tree[nd] = val;
        return;
    }
    update(left, idx, val); /// left
    update(right, idx, val); /// right
    tree[nd] = (tree[nd + nd] + tree[nd + nd + 1]) % MOD;
   /// tree[nd] = max(tree[nd + nd],tree[nd + nd + 1]);
   /// tree[nd] = min(tree[nd + nd],tree[nd + nd + 1]);
   /// tree[nd] = (tree[nd + nd] * tree[nd + nd + 1]) % MOD;
}

ll query(int st, int en, int nd, int L, int R)
{
    if(R < st || en < L) return 0;
    if(L <= st && en <= R) return tree[nd];
    return (query(left,L,R) + query(right,L,R)) % MOD;
}

int main()
{
    int t, n, cs = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            brr[i] = arr[i];
        }
        compress(n);
        ll total_ans = 0;
        for(int i = 0; i < n; i++)
        {
            /// ll query(int st, int en, int nd, int L, int R) [st,en]
            ll sum = 1 + query(1, n, 1, 1, arr[i] - 1);
            total_ans = (total_ans + sum) % MOD;
            update(1, n, 1, arr[i], sum);
        }
        printf("Case %d: %lld\n", cs++, total_ans);
        memset(tree, 0, sizeof(tree));
    }
    return 0;
}
