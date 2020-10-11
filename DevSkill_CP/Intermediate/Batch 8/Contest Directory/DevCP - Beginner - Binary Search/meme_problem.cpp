#include <bits/stdc++.h>
using namespace std;
#define eps 1e-7

int D;

void solve()
{
    double lo, hi, mid, x, y;
    lo = 0.0;
    hi = D;
    int cnt = 100;
    while(cnt--)
    {
        mid = (lo + hi) / 2.0;
        x = mid;
        y = D - mid;
        if(x * y < x + y) lo = mid;
        else hi = mid;
    }
    if(fabs(x * y - (x + y)) > eps) cout << "N\n";
    else
    cout << "Y " << setprecision(9) << fixed << y << " " << x << "\n";
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> D;
        solve();
    }
    return 0;
}