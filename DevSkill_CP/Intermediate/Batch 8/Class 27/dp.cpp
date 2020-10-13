#include <bits/stdc++.h>
using namespace std;

void iter_LIS()
{
    int n;
    cin >> n;
    vector<int>arr(n), dp(n, 1);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max_len = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                max_len = max(max_len, dp[i]);
            }
        }
    }
    cout << max_len << "\n";
}

int main()
{
    iter_LIS();

    return 0;
}
