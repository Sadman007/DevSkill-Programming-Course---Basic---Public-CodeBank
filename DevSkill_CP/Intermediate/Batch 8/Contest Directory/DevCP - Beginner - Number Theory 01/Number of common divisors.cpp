#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,g;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        g = __gcd(a,b);
        int res = 0;
        for(int i=1;i*i<=g;i++)
        {
            if(g%i==0)
            {
                res++;
                if(g!=i*i) res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}