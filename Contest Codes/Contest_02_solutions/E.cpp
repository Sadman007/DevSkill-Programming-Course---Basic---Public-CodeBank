#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    int t, x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);

        int ub = upper_bound(v.begin(), v.end(), x) - v.begin();
        int lb = lower_bound(v.begin(), v.end(), x) - v.begin();
        lb--;

        if (lb >= 0) printf("%d ", v[lb]);
        else printf("X ");

        if (ub < n) printf("%d\n", v[ub]);
        else printf("X\n");
    }
}