#include <bits/stdc++.h>
using namespace std;
long long MOD;

long long bigMod(long long a,long long b)
{
    if(b==0) return 1;
    if(b%2==0)
    {
        long long res = bigMod(a,b/2)%MOD;
        return (res*res)%MOD;
    }
    else
    {
        return (a%MOD*bigMod(a,b-1)%MOD)%MOD;
    }
}
/// 2^64
int main()
{
    MOD = 1000000007;
    cout << bigMod(2,1000000000000000);
    /// string1 = "s[a]kib"
    /// string2 = "s[s]"
    /// string2>string1

    /// Wrong Answer
    /// Time Limit Exceeded
    /// Accepted
    /// (10^9 * 10^10) % 100
    /// (a*b)%M = ((a%M)*(b%M))%M
    /// f(n) = (f(n-1)%M + f(n-2)%M)%M
    /// A%M ---> O(log(M)A)

    /// Time Limit : 1s ( 10^8 ta task )
    /// N = 10^5 O(N^2) 10^10 ta task

    /// NlogB
    /// 2^N MOD M
    /// 2^5 = 32 % 5 = 2

    /// (a+b)^2 + (c+d)^2 = (a+b)^2 + (c+d)^2
    /// 1 3 4 10
    /// (1+3)^2 + (4+10)^2 = 4^2 + 14^2 = 212
    /// (1+4)^2 + (3+10)^2 = 5^2 + 13^2 = 25+169 = 170+24 = 194
    /// (1+10)^2 + (3+4)^2 = 11^2 + 7^2 = 121 + 49 = 120 + 50 = 170

    return 0;
}
