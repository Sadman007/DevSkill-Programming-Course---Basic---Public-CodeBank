#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define left st, (st + en) / 2, 2 * node_no
#define right (st + en) / 2 + 1, en, 2 * node_no + 1

vector<int>arr;
vector<int>tree_node[4 * MAX + 5];

void build_tree(int L, int R, int node_no)
{
    if(L == R)
    {
        tree_node[node_no].push_back(arr[L]);
        return;
    }
    int mid = (L + R) / 2;
    build_tree(L, mid, 2 * node_no);
    build_tree(mid + 1, R, 2 * node_no + 1);
    tree_node[node_no].resize(R - L + 1);
    merge(tree_node[2 * node_no].begin(), tree_node[2 * node_no].end(),
          tree_node[2 * node_no + 1].begin(), tree_node[2 * node_no + 1].end(),
          tree_node[node_no].begin());
}

int less_equal_than_val(int st, int en, int node_no, int L, int R, int val)
{
    if(R < st || en < L) return 0;
    if(L <= st && en <= R)
    {
        int cnt = upper_bound(tree_node[node_no].begin(),
                              tree_node[node_no].end(),
                              val) - tree_node[node_no].begin();
        return cnt;
    }
    return less_equal_than_val(left, L, R, val) + less_equal_than_val(right, L, R, val);
}

int solve(int L, int R, int k, int n)
{
    int low = -1e9 + 1;
    int high = +1e9 + 1;
    int mid;
    while(low < high)
    {
        mid = low + (high - low)/2;
        if(less_equal_than_val(0, n - 1, 1, L, R, mid) >= k)
        {
            high = mid;
        }
        else low = mid + 1;
    }
    return high;
}

/// n (logn)^3

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    arr.clear();
    arr.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    build_tree(0, n - 1, 1);
    while(q--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", solve(a - 1, b - 1, c, n));
    }
    return 0;
}
