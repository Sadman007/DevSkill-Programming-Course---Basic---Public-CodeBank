#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000
#define eps 1e-10

double getSqrt(double n)
{
    double L = 0.0;
    double R = n;
    double M;
    ///while(fabs(L - R) > 0.00000000000000001)
    while(fabs(L - R) >= eps)
    {
        M = (L + R) / 2.0;
        if(M * M > n) R = M;
        else L = M;
    }
    return M;
}

int main()
{
    cout << setprecision(8) << fixed << getSqrt(37.0) << endl;
    return 0;
}
/// [0, 5] --> (2.5)^2 < 10
/// [2.5, 5]
///...
/// [3.1622, 3.1622]
