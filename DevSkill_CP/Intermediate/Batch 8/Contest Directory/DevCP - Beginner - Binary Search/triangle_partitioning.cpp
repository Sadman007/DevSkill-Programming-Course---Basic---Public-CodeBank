#include <bits/stdc++.h>
using namespace std;
#define eps 1e-7

double AB, AC, BC, rat;

double solve()
{
    double s = (AB + BC + AC) * 0.5;
    double area = sqrt(s * (s - AB) * (s - BC) * (s - AC));

    double L, R, M, ab, bc, ac, temp_rat = 1000000000.0;

    L = 0;
    R = 1;

    int cnt = 500;

    while(cnt--)
    {
        M = L + (R - L)/2;

        ab = AB * M;
        bc = BC * M;
        ac = AC * M;

        s = (ab + bc + ac) * 0.5;
        double temp_area = sqrt(s * (s - ab) * (s - bc) * (s - ac));
        double area_rem = area - temp_area;

        double temp_rat = temp_area / area_rem;

        if(temp_rat > rat) R = M;
        else L = M;
    }
    return AB * M;
}

int main()
{
    int cs = 1, T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &rat);
        printf("Case %d: %0.8f\n", cs++, solve());
    }
    return 0;
}
