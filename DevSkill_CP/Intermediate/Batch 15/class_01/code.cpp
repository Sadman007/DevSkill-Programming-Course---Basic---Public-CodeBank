#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0;
    n = 100;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j *= 3)
        {
            sum++;
        }
    }
    cout << sum << "\n";
    return 0;
}
