#include <bits/stdc++.h>
using namespace std;
int arr[200000];
int main()
{
    int q, n, v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &v);
        arr[i] = v + (i ? arr[i - 1] : 0);
    }
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &v);
        printf("%d\n", 1 + lower_bound(arr, arr + n, v) - arr);
    }
    return 0;
}