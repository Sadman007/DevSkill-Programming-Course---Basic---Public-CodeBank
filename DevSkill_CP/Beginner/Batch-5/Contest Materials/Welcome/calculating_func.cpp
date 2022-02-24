#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll res = (n + 1) / 2;
    if(n % 2) res*=-1;
    cout << res << "\n";
    return 0;
}
