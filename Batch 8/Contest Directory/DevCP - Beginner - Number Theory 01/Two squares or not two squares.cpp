#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll num;
        scanf("%lld",&num);
        bool found = 0;
        for(ll i = 1; i * i <= num; i++)
        {
            ll rest = num - 1LL*i*i;
            ll sqr_root = sqrtl(rest);
            if(sqr_root * sqr_root == rest)
            {
                puts("Yes");
                found = 1;
                break;
            }
        }
        if(found == 0) puts("No");
    }
    return 0;
}