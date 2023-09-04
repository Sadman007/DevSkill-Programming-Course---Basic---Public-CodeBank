#include <bits/stdc++.h>
using namespace std;

const int MAX = 100010;
array<int, MAX> arr;

class Node
{
public:
    int pSum, sSum, sum, best;
    Node() {}
    Node(int val)
    {
        pSum = sSum = sum = best = val;
    }
    Node(int a, int b, int c, int d)
    {
        pSum = a;
        sSum = b;
        sum = c;
        best = d;
    }
    void merge_em(Node& left, Node& right)
    {
        pSum = max(left.pSum, left.sum + right.pSum);
        sSum = max(right.sSum, right.sum + left.sSum);
        sum = left.sum + right.sum;
        best = max({left.best, right.best, left.sSum + right.sSum});
    }
};

Node tree[4 * MAX];

void build(int st, int en, int node)
{
    if (st == en)
    {
        tree[node] = Node(arr[st]);
        return;
    }
    int M = (st + en) / 2;
    build(st, M, node + node);
    build(M + 1, en, node + node + 1);
    tree[node].merge_em(tree[node + node], tree[node + node + 1]);
}

Node query(int st, int en, int node, int l, int r)
{
    if (r < st || en < l) return Node(INT_MIN / 2, INT_MIN / 2, 0, INT_MIN / 2);
    if (l <= st && en <= r) return tree[node];
    int M = (st + en) / 2;
    auto left = query(st, M, node + node, l, r);
    auto right = query(M + 1, en, node + node + 1, l, r);
    Node result = Node(0);
    result.merge_em(left, right);
    return result;
}

int main()
{
    int n, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    build(0, n - 1, 1);
    scanf("%d", &q);
    while(q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", query(0, n - 1, 1, l - 1, r - 1).best);
    }
    return 0;
}
