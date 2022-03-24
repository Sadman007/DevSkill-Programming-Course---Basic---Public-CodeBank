#include <bits/stdc++.h>
using namespace std;

int get_lower_bound(vector<int>&arr, int v)
{
    int L = 0, R = arr.size();
    while(L < R)
    {
        int M = L + (R - L) / 2;
        if (arr[M] >= v)
        {
            R = M;
        }
        else
        {
            L = M + 1;
        }
    }
    return L;
}

int get_upper_bound(vector<int>&arr, int v)
{
    return get_lower_bound(arr, v + 1);
}

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        int n, q;
        scanf("%d %d", &n, &q);
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Case %d:\n", cs++);
        while(q--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            int lb = get_lower_bound(arr, a);
            int ub = get_upper_bound(arr, b);
            printf("%d\n", ub - lb);
        }
    }
    return 0;
}
