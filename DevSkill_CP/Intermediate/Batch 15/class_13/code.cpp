#include <bits/stdc++.h>
using namespace std;

// isPalindrome detects whether str[L...R] is a palindrome or not.
bool isPalindrome(string &str, int L, int R)
{
    if (L >= R) return true;
    return (str[L] == str[R]) and (isPalindrome(str, L + 1, R - 1));
}

bool isPalindrome(string &str)
{
    return isPalindrome(str, 0, str.size() - 1);
}

long long expo(long long a, long long b, long long M)
{
    if (b == 0) return 1;
    if (b % 2 == 0)
    {
        auto half = expo(a, b / 2, M) % M;
        return (half * half) % M;
    }
    return (a * expo(a, b - 1, M)) % M;
}

int main()
{
    cout << expo(5, 100, 7) << "\n";
    return 0;
}
