#include <bits/stdc++.h>
using namespace std;
#define MAX 10010

int n,m,arr[MAX];

bool cmp(int a,int b)
{
    int ma = a % m;
    int mb = b % m;
    if(ma == mb && a%2 != b%2)
    {
        if(a % 2 == 1) return 1;
        return 0;
    }
    if(ma == mb && a%2 == b%2 && a%2==1)
    {
        return a > b;
    }
    if(ma == mb && a%2 == b%2 && a%2==0)
    {
        return a < b;
    }
    return ma < mb;
}

int main()
{
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n == 0 && m == 0) break;
        for(int i=0; i<n; i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+n,cmp);
        for(int i=0; i<n; i++)
        {
            printf("%d\n",arr[i]);
        }
    }
    return 0;
}
