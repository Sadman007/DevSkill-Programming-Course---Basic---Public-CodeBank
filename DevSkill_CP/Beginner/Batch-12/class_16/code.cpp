#include <bits/stdc++.h>
using namespace std;

// Def:
//  getExpo(a, b) parameter hishebe nibe a ebong b ke,
//  and ei function er return value hobe a ^ b er maan.

/**
    Example:
        getExpo(5, 2) = 25
        getExpo(a, 0) = 1
**/

long long getExpo(long long a, long long b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        long long r = getExpo(a, b / 2);
        return r * r;
    }
    return a * getExpo(a, b - 1);
}

int main()
{
    cout << getExpo(2, 10000000000) << "\n";
    return 0;
}
