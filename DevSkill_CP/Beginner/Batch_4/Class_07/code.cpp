#include <bits/stdc++.h>
using namespace std;

bool isSubstring(string &s1, string &s2) /// O(N * x) = O((|s1| - |s2|)*(|s2|)) = O(|s1||s2|)
{
    for(int i = 0; i <= s1.size() - s2.size(); i++) /// O(N) -> N = |s1| - |s2|
    {
        string sub_str = s1.substr(i, s2.size()); /// O(x) -> x = |s2|
        if(sub_str == s2) return true;
    }
    return false;
}

void t1()
{
    /**
    string s1, s2;
    cin >> s1 >> s2;
    cout << isSubstring(s1, s2) << "\n";
    **/

    int n;
    cin >> n;
    long long cnt = 0;
    for(int i = 1; i <= n; i++) /// O(N)
    {
        for(int j = 1; j <= n; j++) /// O(N)
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main() /// O(T * N^2) => T = 10^3 , N = 10^5 => 10^3 * 10^5 * 10^5 = 10^13 / 10^8 => 10^(13-8) = 10^5s
{
    int t;
    cin >> t;
    while(t--) /// O(T * (logW + logH))
    {
        int w, h, n;
        cin >> w >> h >> n;
        int x, y, tot_cnt;
        x = y = 0;
        while(w > 0 && w % 2 == 0) /// O(logW)
        {
            w /= 2;
            x++;
        }
        while(h > 0 && h % 2 == 0) /// O(logH)
        {
            h /= 2;
            y++;
        }
        tot_cnt = 1 << (x + y); /// 2 ^ (x + y) = 1 << (x + y)
        if(tot_cnt >= n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
