#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool prime[1000001];
int main()
{
    prime[1] = 1;
    for(int i = 2; i<=1000; i++)
    {
        if(prime[i] == 0)
        {
            for(int j = i*i; j<=1000000; j+=i)
            {
                prime[j] = 1;
            }
        }
    }
    int cs;
    scanf("%d", &cs);
    while(cs--)
    {
        ll n;
        scanf("%lld", &n);
        ll sqr=0;
        sqr = sqrtl(n);
        if(sqr*sqr==n && prime[sqr]==0)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}