#include <bits/stdc++.h>
using namespace std;

int get_factorial(int n) /// get_factorial(n) = n * get_factorial(n - 1)
{
    /// base case
    if (n == 0)
    {
        return 1;
    }
    return n * get_factorial(n - 1);
}

int main()
{
    int value = get_factorial(5);
    cout << value << endl;
    return 0;
}
