#include <bits/stdc++.h>
using namespace std;
/// 500 -> 5x10^2 ---> 154851546 -> 1.54851 x 10^800
#define eps 1e-6

double sqrt_helper(double N)
{
    double L, R, M;
    L = 0.0;
    R = max(1.0, N); /// R = max(1.0, 1.0*N)
    int cnt = 80;
    while(cnt--)
    {
        M = (L + R) / 2;
        if(M * M > N) /// L = 0, R = 10 M * M = 25
        {
            R = M;
        }
        else
        {
            L = M;
        }
    }
    return M;
}



int main()
{
    double N;
    while(cin >> N)
    cout << setprecision(10) << fixed << sqrt_helper(N) << "\n";
    return 0;
}
