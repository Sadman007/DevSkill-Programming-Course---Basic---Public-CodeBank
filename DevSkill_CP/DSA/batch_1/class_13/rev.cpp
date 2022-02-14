#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int L, int R)
{
    /// base case
    if (L > R) return true;
    return (str[L] == str[R]) && isPalindrome(str, L + 1, R - 1);
}

long long dp[10000];

long long fib(int n)
{
    if (n < 2) return n;
    if (dp[n] != -1) return dp[n];
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

void solveHanoi(char src, char intr, char dest, int n)
{
    if (n == 0) return;
    solveHanoi(src, dest, intr, n - 1);
    cout << src << " -> " << dest << "\n";
    solveHanoi(intr, src, dest, n - 1);
}

int main()
{
    /*
    string str;
    cin >> str;
    cout << isPalindrome(str, 0, str.size() - 1) << "\n";

    memset(dp, -1, sizeof dp);
    cout << fib(9500);
    */

    solveHanoi('A', 'B', 'C', 3);
    return 0;
}
