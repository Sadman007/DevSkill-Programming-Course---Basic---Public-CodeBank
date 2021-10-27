#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1e18
#define MOD 1000000007

ll factorial(int n, ll res)
{
    if (n == 0) return res;
    return factorial(n - 1, (res * n) % MOD);
}

bool isPalindrome(string &s, int L, int R) // abba -> L = 2, R = 1
{
    if (L >= R) return true;
    if (s[L] != s[R]) return false;
    return isPalindrome(s, L + 1, R - 1);
}

vector<ll>specialNumber;
unordered_set<ll>track;

/// O(k)
void generateSpecialNumber(ll num)
{
    if (num > MAX || track.count(num)) return;
    specialNumber.push_back(num);
    track.insert(num);
    generateSpecialNumber(num * 2);
    generateSpecialNumber(num * 3);
}

int main()
{
    //cout << factorial(500000, 1);
    //string s = "aacba";
    //cout << isPalindrome(s, 0, s.size() - 1);
    generateSpecialNumber(1);
    sort(specialNumber.begin(), specialNumber.end());
    for (auto k : specialNumber)
        cout << k << "\n";
    return 0;
}
