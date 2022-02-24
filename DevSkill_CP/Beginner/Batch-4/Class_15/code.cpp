#include <bits/stdc++.h>
using namespace std;

int fib(int n) /// fib(5)
{
    cout << "now inside f(" << n << ")\n";
    getchar();
    if(n < 3)
    {
        cout << "base case!\n";
        getchar();
        return n;
    }
    int res = fib(n - 1) + fib(n - 2) + fib(n - 3);
    return res;
}

int up(int a, int b)
{
    if(a == 1 && b == 1) return 0;
    if(a < 1 || b < 1) return INT_MAX / 2;
    if(a > b) return 1 + up(a - b, b);
    else return 1 + up(a, b - a);
}

int main()
{
    int n;
    cin >> n;
    int best = INT_MAX / 2;
    for(int i = 1; i <= n; i++)
    {
        best = min(best, up(i, n));
    }
    cout << best << "\n";
    return 0;
}
