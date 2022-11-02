#include <bits/stdc++.h>
using namespace std;

/**
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        /// task
        for (int j = i; j <= n; j++) /// (n) + (n - 1) + (n - 2) + .. + (n - (n - 1)) = n * (n + 1) / 2
        {
            for (int k = j + j; k <= n; k += 2)
            {

            }
        }
    }
    **/

int main()
{
    int arr[5][5];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/**
4 + 3 + 2 + 1 = 10
5 + 4 + 3 + 2 + 1 = 15

6 -> 1 + 2 + 3+ 4 + 5+ 6 = 6 * 7 / 2
**/
