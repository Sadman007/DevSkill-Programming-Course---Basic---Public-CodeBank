#include <bits/stdc++.h>
using namespace std;
#define MAX 100006

int arr[MAX];

int main()
{
    int t, n, Q, cs = 1;
    scanf("%d", &t);
    while(t--)
    {
       scanf("%d %d", &n, &Q);
       for(int i=0;i<n;i++) scanf("%d",&arr[i]);
       printf("Case %d:\n",cs++);
       while(Q--)
       {
           int L,R;
           scanf("%d %d",&L,&R);
           int ub = upper_bound(arr,arr+n,R) - arr; /// O(log2(N))
           int lb = lower_bound(arr,arr+n,L) - arr; /// O(log2(N))
           printf("%d\n",ub - lb);
       }
    }
    return 0;
}