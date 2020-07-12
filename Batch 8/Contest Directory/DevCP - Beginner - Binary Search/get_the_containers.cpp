#include <bits/stdc++.h>
using namespace std;
int sum,n,m,arr[1010];

int f(int val)
{
    int cap_val = 0;
    int container = 1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>val) return 0;
        if(cap_val+arr[i]<=val) cap_val+=arr[i];
        else
        {
            container++;
            cap_val = arr[i];
        }
    }
    return container<=m;
}

int main() {
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) {scanf("%d",&arr[i]); sum+=arr[i];}
        int lo,hi,md,cnt=60;
        lo = 1;
        hi = 2e9;
        while(cnt--)
        {
            if(lo>hi) break;
            md = (lo+hi)/2;
            if(f(md))
            {
                hi = md;
            }
            else lo = md+1;
        }
        printf("Case %d: %d\n",cs++,md);
    }

    return 0;
}