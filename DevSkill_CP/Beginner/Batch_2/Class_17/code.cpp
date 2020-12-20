#include <bits/stdc++.h>
using namespace std;

int f(int n) /// f(5)
{
    if(n == 0) return 1; /// done
    int res = n * f(n - 1); /// done
    return res; /// done
}

bool isPalindrome(int L, int R, string &s)
{
    //cout << L << " " << R << "\n";
    //getchar();
    if(L >= R) return true;
    if(s[L] == s[R]) return isPalindrome(L + 1, R - 1, s);
    return false;
}

int get(string x_prv, string x, int i) /// [42], [2], 1, 1
{
    //cout << x_prv << " " << x << " " << i << "\n";
    //getchar();
    if(x_prv == x) return i;
    return get(x, to_string(x.length()) , i + 1);
}

int main()
{
    //cout << f(5) << "\n"; /// 120
    /**
    string str = "abxyzyxba";
    cout << isPalindrome(0, str.size() - 1, str) << "\n";
    **/
    string str;
    while(cin >> str)
    {
       if(str == "END") break;
       cout << get("", str, 0) << "\n";
    }
    return 0;
}
