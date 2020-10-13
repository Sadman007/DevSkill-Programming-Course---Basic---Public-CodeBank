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

//int n, dp[1010], arr[1010];
/// 3 1 2 5 2 4 5
int f(int pos)
{
    if(pos >= n) return 0;
    if(dp[pos] != -1) return dp[pos];
    int res = 1;
    for(int i = pos; i < n; i++)
    {
        if(arr[pos] < arr[i])
            res = max(res, 1 + f(i + 1));

        res = max(res, f(i + 1));
    }
    return dp[pos] = res;
}

void recur_LIS()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    //f(0);
    cout << f(0) << "\n";
    //cout << f(0) << "\n";
}




int main()
{
    ///iter_LIS();
    ///recur_LIS();

    return 0;
}
