#include <bits/stdc++.h>
using namespace std;

/**
    O(N / W) --> W = bit architecture (32,64)

    N shongkhok number 1<=N<=10^7
    1<=value<=10^9

    unique value koyta ase?

    N = 5
    1 2 3 1 2

    3
**/

int n, x, target; /// O(N * T)

bitset<1000001>dp; /// O(N * T / 64)

int main()
{
    dp[0] = 1;
    cin >> n >> target;
    for(int i = 0; i < n; i++) /// O(N)
    {
        cin >> x;
        /*
        for(int w = target; w >= x; w--) /// O(T)
        {
            if(dp[w - x] == 1) dp[w] = 1;
        }
        */
        dp |= (dp << x); /// O(T / 64)
    }
    for(int i = 0; i <= target; i++) cout << dp[i] << " ";
    cout << "\n";
    if(dp[target] == 1) puts("YES");
    else puts("NO");

    return 0;
}
