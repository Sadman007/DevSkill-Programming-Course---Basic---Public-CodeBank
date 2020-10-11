#include <bits/stdc++.h>
using namespace std;
int arr[100010];

int main() {
    int t,n,q,L,R,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        printf("Case %d:\n",cs++);
        while(q--)
        {
            scanf("%d %d",&L,&R);
            printf("%d\n",upper_bound(arr,arr+n,R)-lower_bound(arr,arr+n,L));
        }
    }
    return 0;
}