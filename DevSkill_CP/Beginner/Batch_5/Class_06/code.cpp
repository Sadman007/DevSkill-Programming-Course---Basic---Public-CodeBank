#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; /// 1 <= n <= 10^20
    cin >> n >> k; /// 1 <= k <= 10^6

    /// O(n * (k + logn))
    for(int i = 0; i <= n; i++)
    {
        /// O(logn) = 20 task
        for(int j = 1; j <= n; j = j * 2)
        {
            cout << i + j << " ";
        }
        /// O(k) = 10^6 task
        for(int x = 0; x <= k; x++)
        {
            /// some stuffs
        }
    }
    return 0;
}

/**
    input : n
    output (number of execution) : n * (logn + k)

    O(number of execution) = O(n * k)


    O(2^n * (n^2 + log2(n) ^2 + k)) // n = 15, k = 100
**/
