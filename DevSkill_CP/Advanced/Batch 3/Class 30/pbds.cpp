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
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int lucky[100010];
ordered_set ost;
/// a + (n - 1) * d
void init()
{
    for(int i = 1; i <= LIM; i = i + 2)
        ost.insert(i);

    for(int turn = 2; turn <= 8773; turn++) /// O(Nlog^2N), N = LIM
    {
        int d = *ost.find_by_order(turn - 1) - 1; /// d = 7 , d--, d = 6
        int a = d; ///a = 6
        while(1) ///
        {
            if(a >= ost.size()) break;
            ost.erase(*ost.find_by_order(a));
            a += d;
        }
    }
    for(int i = 0; i < 100000; i++)
    {
        lucky[i] = *ost.find_by_order(i);
    }
}

int main()
{
    init();
    int T, N, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        printf("Case %d: %d\n", cs++, lucky[N - 1]);
    }
    return 0;
}
