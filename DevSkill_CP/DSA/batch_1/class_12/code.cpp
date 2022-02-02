#include <bits/stdc++.h>
using namespace std;

int LB(vector<int>&arr, int v) /// O(logN)
{
    int L = 0, R = arr.size();
    while(L < R)
    {
        int M = (L + R) / 2;
        if (arr[M] < v)
        {
            L = M + 1;
        }
        else
        {
            R = M;
        }
    }
    return L;
}

int UB(vector<int>&arr, int v)
{
    return LB(arr, v + 1);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T, v, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        printf("Case %d:\n", cs++);
        int n, q;
        scanf("%d %d", &n, &q);
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &v);
            arr.push_back(v);
        }
        while(q--)
        {
            int L, R;
            scanf("%d %d", &L, &R);
            printf("%d\n", UB(arr, R) - LB(arr, L));
        }
    }
    return 0;
}
