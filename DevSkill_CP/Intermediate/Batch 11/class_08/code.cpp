#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define eps 1e-8

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int d;
        scanf("%d", &d);
        if (d == 0)
        {
            printf("Y %d %d\n", d, 0);
            continue;
        }
        else if (d == 4)
        {
            printf("Y %d %d\n", 2, 2);
            continue;
        }
        double L = 1, R = d, M, dD = 1.0 * d;
        int cnt = 60;
        while(cnt--)
        {
            M = (L + R) / 2; /// M is a candidate of 'a'
            double b = dD - M;
            if (M * b > dD)
            {
                R = M;
            }
            else
            {
                L = M;
            }
        }
        if(fabs((M * (d - M)) - d) > eps) /// a != b => fabs(a - b) > eps
        {
            printf("N\n");
        }
        else
        {
            printf("Y %0.9f %0.9f\n", d - M, M);
        }
    }
    return 0;
}
