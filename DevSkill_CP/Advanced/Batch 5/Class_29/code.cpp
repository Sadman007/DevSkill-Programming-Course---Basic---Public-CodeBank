#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

int main()
{
    int n, v, T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int neg = 0;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &v);
            sum += abs(v);
            if(v < 0) neg++;
        }
        int up = sum;
        int dw = n - neg;
        if(dw == 0)
        {
            printf("Case %d: inf\n", cs++);
            continue;
        }
        int gg = __gcd(up, dw);
        up /= gg;
        dw /= gg;
        printf("Case %d: %d/%d\n", cs++, up, dw);
    }
    return 0;
}
