#include <bits/stdc++.h>
using namespace std;

long long arr[200010], flag[200010];
long long n, m, w;

bool isPossible(long long X)
{
    /**
     2 2 2 [2] 1 1 --> isPossible(0) --> true
     0 0 0 3 0 0 3
     L = 0, R = 10, w = 3, m = 2

     M = 1
     isPossible(1)

    **/
    memset(flag, 0, sizeof(flag));
    /// 0 0 0 3 0 0
    long long res = 0;
    long long runningSum = 0;

    for(int i = 0; i < n; i++) /// n = 6
    {
        runningSum -= flag[i]; /// 3 - 3 = 0
        if(arr[i] + runningSum < X) /// 2 + 0 < 5
        {
            long long temp = X - (arr[i] + runningSum); /// 3
            res += temp; /// res = 3 + 3 = 6
            runningSum += temp; /// runningSum = 3
            flag[i + w] += temp; /// flag[3 + 3] = 3
        }
    }
    return res <= m;
}

int main()
{
    cin >> n >> m >> w;
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long L, M, R, ans;
    L = 0;
    ///R = 1000000005LL + 200005LL; /// confused
    R = 10000000000000LL;

    while(L < R)
    {
        M = L + (R - L)/2;
        if(isPossible(M)) L = M + 1;
        else R = M;
    }
    cout << L - 1 << "\n";

    return 0;
}

