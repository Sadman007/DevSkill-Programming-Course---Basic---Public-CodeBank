#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000

/// O(n)
/// Not modulo arithmetic friendly!
ll nCr(int n, int r) {
    int gap = min(r, n - r); /// 50 - 47 = 3
    ll res = 1;
    int a = n;
    int b = 1;
    while(gap--) {
        res *= a;
        res /= b;
        a--;
        b++;
    }
    return res;
}

/**
    (a * b) mod M = ((a mod M) * (b mod M)) mod M
    (a + b) mod M = ((a mod M) + (b mod M)) mod M
    (a - b) mod M = ((a mod M) - (b mod M)) mod M
**/
/// Modulo arithmetic friendly!
ll fact(int n) {
    ll res = 1;
    for(int i = 1; i <= n; i++) {
        res = (res * i) % 48967683987LL;
    }
    return res;
}

int main()
{
    cout << fact(125) << endl;
    //cout << nCr(50, 47);
    return 0;
}
