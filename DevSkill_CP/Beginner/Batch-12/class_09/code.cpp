#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-4

double find_sqrt(int N)
{
    double L = 0, R = N, M = N;
    while(fabs(L - R) > EPS)
    {
        M = (L + R) / 2;
        if (M * M > N) R = M;
        else L = M;
    }
    return R;
}

int main()
{
    int N;
    cin >> N;
    cout << find_sqrt(N) << "\n";
    main();
    return 0;
}
