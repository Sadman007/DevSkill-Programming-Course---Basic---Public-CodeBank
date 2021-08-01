#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000

string s1, s2;
int dp[MAX + 5][MAX + 5];

int getLCS(int p1, int p2)
{
    if(p1 >= s1.size() || p2 >= s2.size()) return 0;
    int &ret = dp[p1][p2];
    if(ret != -1) return ret;
    ret = 0;
    if(s1[p1] == s2[p2] && p1 != p2)
        ret = max(ret, 1 + getLCS(p1 + 1, p2 + 1));
    ret = max({ret, getLCS(p1, p2 + 1), getLCS(p1 + 1, p2)});
    return ret;
}

int egcd(int a, int b, int &x0, int &y0)
{
    if(b == 0)
    {
        x0 = 1;
        y0 = 0;
        return a;
    }
    int x1, y1;
    int gcd = egcd(b, a % b, x1, y1);
    x0 = y1;
    y0 = x1 - (y1 * (a / b));
    return gcd;
}

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    /*
    s1 = "a1a2a3";
    /// a1a2
    /// a2a3
    s2 = s1;
    memset(dp, -1, sizeof dp);
    cout << getLCS(0, 0);
    */
    /// ax + by = c
    /// c % gcd(a, b) != 0, no solution
    /// c / gcd(a, b)
    int x, y;
    egcd(55, 80, x, y);
    cout << x << " " << y;
    return 0;
}
