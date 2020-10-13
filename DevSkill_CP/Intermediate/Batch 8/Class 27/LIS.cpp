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

int n, arr[1000], dp[1010][1010];

int f(int pos, int prv)
{
	if(pos == n) return 0;
	if(prv >= 0 && dp[pos][prv] != -1) return dp[pos][prv];
	int add, notAdd;
	add = notAdd = 0;
	if(prv < 0 || arr[pos] > arr[prv])
		add = 1 + f(pos + 1, pos);
	notAdd = f(pos + 1, prv);
	dp[pos][prv] = max(add, notAdd);
	return dp[pos][prv];
}

void recur_LIS()
{
    cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	cout << f(0, -1) << "\n";
}

int main()
{
    iter_LIS();
    recur_LIS();
    return 0;
}
