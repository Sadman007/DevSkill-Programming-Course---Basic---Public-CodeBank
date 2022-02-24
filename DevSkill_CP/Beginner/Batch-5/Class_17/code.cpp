#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100000


/// n! = n * (n - 1)!
/// f(n) = n * f(n - 1)

/// f(L, R) = (str[L] == str[R]) && (f(L + 1,R - 1))
/// [c]baab[c]
bool isPalindrome(int L, int R, string &str)
{
    if(L >= R) return true;
    return (str[L] == str[R]) && (isPalindrome(L + 1, R - 1, str));
}

/**
n = 3
--------
4

44

444

4444

**/

vector<ll>luckyNumbers; /// 4, 44, 444

bool isSuperLucky(string &luckyNumber)
{
    int c4, c7;
    c4 = c7 = 0;
    for(auto c : luckyNumber)
    {
        if(c == '4') c4++;
        else c7++;
    }
    return c4 == c7;
}

void genLuckyNumbers(int n, string &luckyNumber)
{
    if(luckyNumber.size() > n) return;
    if(luckyNumber.size() > 0 && isSuperLucky(luckyNumber))
        luckyNumbers.push_back(stoll(luckyNumber));

    luckyNumber.push_back('4');
    genLuckyNumbers(n, luckyNumber);
    luckyNumber.pop_back();

    luckyNumber.push_back('7');
    genLuckyNumbers(n, luckyNumber);
    luckyNumber.pop_back();
}

int main()
{
    //string str = "ab";
    //cout << isPalindrome(0, 1, str) << "\n";
    string luckyNumber = "";
    genLuckyNumbers(10, luckyNumber);
    sort(luckyNumbers.begin(), luckyNumbers.end());
    ll n;
    cin >> n;
    cout << *lower_bound(luckyNumbers.begin(), luckyNumbers.end(), n) << "\n";

    return 0;
}
