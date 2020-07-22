#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define LIM 1429432
#define ll long long

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;


typedef tree<
pair<int, int>,
null_type,
less<pair<int, int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ordered_set ost;

int main()
{
    int n, x, y, len = 1;
    scanf("%d", &n);
    vector<int>ans(n + 1, 0);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y); /// (1,1)
        ans[ost.order_of_key({x, len++})]++; /// level
        ost.insert({x, len});
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
