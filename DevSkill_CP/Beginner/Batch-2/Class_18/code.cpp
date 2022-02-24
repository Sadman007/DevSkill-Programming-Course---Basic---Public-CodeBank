#include <bits/stdc++.h>
using namespace std;

void f1(int n)
{
    if(n > 1) f1(n - 1);
    // task
    for(int i = 0; i < n; i++)
        cout << " * ";

    cout << "\n";
}

void printBin(int n)
{
    if(n == 0) return;

    printBin(n / 2);
    cout << n % 2;
}

void helper(int n)
{
    if(n == 0)
    {
        cout << "0\n";
        return;
    }
    printBin(n);
}

int n;
int solE(int a, int b)
{
    //cout << a << " " << b << "\n";
    //getchar();
    if(a == n || b == n || a > (2*n) || b > (2*n)) return 0;
    int r1 = solE(a + b, b);
    int r2 = solE(a, a + b);
    return min(r1, r2) + 1;
}

int main()
{
    //f1(3);
    //int n = 1;
    //helper(n);
    for(n = 1; n <= 100; n++)
        cout << n << " : " << solE(1, 1) << "\n";
    return 0;
}
