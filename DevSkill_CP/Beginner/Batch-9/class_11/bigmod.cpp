#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

/// getExpo(a, b) = a * getExpo(a, b - 1)
/// getExpo(a, b) = (getExpo(a, b / 2))^2
/// O(log2(B))

ll getExpo(ll a, ll b)
{
    if (b == 0) return 1;
    if (b % 2 == 0)
    {
        ll half = getExpo(a, b / 2) % MOD;
        return (half * half) % MOD;
    }
    return (a * getExpo(a, b - 1)) % MOD;
}

int main()
{
    cout << getExpo(5, 700000000) << "\n";
    return 0;
}

// 169385989
