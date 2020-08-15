#include <bits/stdc++.h>
using namespace std;
#define MAX 1e10
bool pal_check(string &str, int L, int R)
{
    if(L >= R) return 1;
    if(str[L] != str[R]) return 0;
    return pal_check(str, L + 1, R - 1);
}

void do_pal()
{
    string str = "abcba";
    cout << pal_check(str, 0, (int)str.size() - 1);
}

unordered_map<long long, bool>exists;

void funny_gen(long long num)
{
    if(num > MAX) return;
    if(exists.find(num) != exists.end()) return;
    exists[num] = true;
    funny_gen(num * 5);
    funny_gen(num * 3);
}

int main()
{
    funny_gen(1);
    cout << exists.size() << "\n";
    return 0;
}
