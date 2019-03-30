#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,i,n,ans;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        ans = (sqrt(1+4*2*n)-1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}